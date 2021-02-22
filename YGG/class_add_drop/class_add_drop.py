#/usr/bin/python3
#pip3 install requests Pillow BeautifulSoup4 
import requests , re , getpass ,json , time , urllib3
from PIL import Image
from io import BytesIO
from bs4 import BeautifulSoup
urllib3.disable_warnings()
### 學號 密碼
username = ""
passwd = ""
## https://aisap.nutc.edu.tw/public/day/course_list.aspx?sem=1092
# 找出想要選的課程的課程代碼 (四位數的數字) 不要有英文字母
# 如果同時段有多門想上的 (像是通識?) 越想上的放越前面 (因為有課了會被直接當作衝堂)
# 假如1178 是目標，再來是1234，而5767保底  如範例:
add_class = {"5682"}

# 如果有預選想先退掉 寫這裡
drop_class = {"1134","1178"}
###
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36'}
session = requests.Session()
session.cookies.clear_session_cookies()
ASP_Vcode = session.post("https://sso.nutc.edu.tw/ePortal/Validation_Code.aspx",verify=False,headers=headers)

g_a= session.post("https://sso.nutc.edu.tw/ePortal/Default.aspx",verify=False,headers=headers)
login = BeautifulSoup(g_a.text, 'html.parser')
VIEWSTATE = (re.search(r'id="__VIEWSTATE" value="(.*?)"', str(g_a.text)).group(1))
EVENTVALIDATION = (login.find(id="__EVENTVALIDATION").get('value'))
###
#open('ASP_Vcode.jpg', 'wb').write(ASP_Vcode.content)
Image.open(BytesIO(ASP_Vcode.content)).show()
###
Vcode = input("驗證碼:")
my_data =   { 
                '__VIEWSTATE': VIEWSTATE , 
                '__EVENTVALIDATION': EVENTVALIDATION, 
                'ctl00$ContentPlaceHolder1$Account': username , 
                'ctl00$ContentPlaceHolder1$Password': passwd, 
                'ctl00$ContentPlaceHolder1$Login.x': '0', 
                'ctl00$ContentPlaceHolder1$Login.y': '0', 
                'ctl00$ContentPlaceHolder1$ValidationCode': Vcode
            }
try:
    home = session.post("https://sso.nutc.edu.tw/ePortal/Default.aspx",data=my_data,verify=False,headers=headers)
    islogin = BeautifulSoup(home.text, 'html.parser')
    islogin.find(id="blank_01_content").find(height="60").text.split(' ')[0]
    print("ePortal登入成功")
    st_url = islogin.select('li:-soup-contains("學生管理系統")')
    st_url = re.search(r'<a href="(.*?)"', str(st_url)).group(1)
    st = session.post(st_url,verify=False,headers=headers)
    print("學生管理系統登入成功")
    print(BeautifulSoup(st.text, 'html.parser').find(class_="PeoPleNote").text)
except:
    print("登入失敗")
    exit()


def add(ccid):
    myclass = {"strParam":"{\"ccid\":\"" + ccid + "\",\"op\":\"add\",\"token\":\"" + token + "\",\"type\":\"curr_sel\"}"}
    check = session.post("https://ais.nutc.edu.tw/student/WebService.asmx/stuClassMod",json=(myclass),headers=headers).text
    c_result = re.search(r'args\\":\[\\"(.*?)\\"]},\{\\"type', str(check)).group(1)
    time.sleep(0.5)
    return c_result
def drop(ccid):
    myclass = {"strParam":"{\"ccid\":\"" + ccid + "\",\"op\":\"drop\",\"token\":\"" + token + "\",\"type\":\"curr_sel\"}"}
    check = session.post("https://ais.nutc.edu.tw/student/WebService.asmx/stuClassMod",json=(myclass),headers=headers).text
    c_result = re.search(r'args\\":\[\\"(.*?)\\"]},\{\\"type', str(check)).group(1)
    time.sleep(0.5)
    return c_result

while True:
    try:
        st = session.post(st_url,verify=False,headers=headers)
        home = session.post("https://ais.nutc.edu.tw/student/selection/class_add_drop.aspx",verify=False,headers=headers)
        token = re.search(r"token:'(.*?)'", str(home.text)).group(1)
        #token = "0a81db99-eeb2-4476-97f9-2877ae216836"
        break
    except:
        print("選課系統尚未開放登入")
        time.sleep(2)
        continue
for i in drop_class :
    print(str(i) + "：" + drop(i))
for j in add_class :
    print(str(j) + "：" + add(j))