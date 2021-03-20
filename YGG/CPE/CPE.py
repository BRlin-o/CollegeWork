#/usr/bin/python3
#pip3 install requests Pillow BeautifulSoup4
###注意###
#請先在開放報名前自己用網頁登入看一下想報名的學校的ID
#在選考場的下拉是選單那邊，右鍵 -> 檢查 (請愛用Chrome)
#點開Select標籤 找出要報的學校 更改下方的school參數
#
import requests , re , getpass ,json , time , urllib3
from PIL import Image
from io import BytesIO
from bs4 import BeautifulSoup
urllib3.disable_warnings()
### 身分證 密碼
username = ""
passwd = ""
school = "9"
# 9 在這場(2021-03-23) 是台中科技科大
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36'}
session = requests.Session()

##用來防止CPE網頁炸掉 先確定能建立連線再下一步
while True:
    try :
        session.cookies.clear_session_cookies()
        login_web = session.post("https://cpe.cse.nsysu.edu.tw/cpe/",verify=False,headers=headers, timeout=2)
        break
    except:
        print("重新連接")
        time.sleep(0.3)
###

try:
    login = BeautifulSoup(login_web.text, 'html.parser')
    Vcode = (re.search(r'captcha/(.*?)"', str(login_web.text)).group(1))
### 選擇圖片顯示方式
    Image.open(BytesIO(session.post("https://cpe.cse.nsysu.edu.tw/cpe/captcha/" + Vcode ,verify=False,headers=headers).content)).show()
    #open('ASP_Vcode.jpg', 'wb').write(session.post("https://cpe.cse.nsysu.edu.tw/cpe/captcha/" + Vcode ,verify=False,headers=headers).content)
###
    VCode = input("請輸入驗證碼：")
except:
    print("網頁有更動過，快手動搶吧XD")
    exit()

login_data =   { 
                'isFirst': 'no' , 
                'myLevel': 'on', 
                'id': username , 
                'pw': passwd, 
                'captcha': VCode
}

try:
    home = session.post("https://cpe.cse.nsysu.edu.tw/cpe/",data=login_data,verify=False,headers=headers)
    account_ = re.search(r'<li><a>(.*?)</a></li>', str(home.text)).group(1)
    main_ = BeautifulSoup(home.text, 'html.parser')
    print("登入成功！")
    print("身分證：" + account_)
    print("學校：" + main_.find('select',attrs={'name': "mySchoolID"}).find(attrs={'selected':True}).text)
    print("年級：" + main_.find('select',attrs={'name': "myGrade"}).find(attrs={'selected':True}).text)
    print("學系：" + main_.find(attrs={'name': "myDepartment"}).get('value'))
    print("要報名的場次：" + main_.find('select',attrs={'name': "site"}).find(value=school).text)
    # print("學校代碼：" + main_.find('select',attrs={'name': "mySchoolID"}).find(attrs={'selected':True}).get('value'))
    # print("年級編號：" + main_.find('select',attrs={'name': "myGrade"}).find(attrs={'selected':True}).get('value'))
    # print("要報名的場次編號：" + main_.find('select',attrs={'name': "site"}).find(value=school).get('value'))
except:
    print("驗證碼錯誤")
    exit()

try:
    print("確定開始刷考場請按任意鍵")
    input()
except:
    print("驗證碼錯誤")
    exit()

while True :
    try:
        add_data =   { 
                        'isSend': 'yes' , 
                        'mySchoolID': main_.find('select',attrs={'name': "mySchoolID"}).find(attrs={'selected':True}).get('value'), 
                        'myDepartment': main_.find(attrs={'name': "myDepartment"}).get('value') , 
                        'myGrade': main_.find('select',attrs={'name': "myGrade"}).find(attrs={'selected':True}).text, 
                        'optionsRadios1': '1',
                        'site': school, 
                        'yesExam': '報名' , 
        }
        while True:
            run = session.post("https://cpe.cse.nsysu.edu.tw/cpe/newest",data=add_data,headers=headers)
            check = re.search(r'<strong>(.*?)</strong>', str(run.text)).group(1)
            print(check)
    except:
        print("莫名其妙炸掉了 也許是網路BOOM")
        time.sleep(0.3)

