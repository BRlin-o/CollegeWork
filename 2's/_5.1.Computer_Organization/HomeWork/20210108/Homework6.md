# Homework 6
## 6-1
### 1. 設採用直接對映式快取的計算機具有容量為220個位元組的以位元組定址的主記憶體以及32個區塊的快取，每個快取區塊內含16個位元組。
- 主記憶體中有多少個區塊?
    > $2^{20}/2^{4} = 2^{16}$
- 快取所見的記憶體位址格式為何?也就是標籤、區快與位移的欄位大小各若干?
    > 20-bit addresses with 11 bits in the tag field, 5 in the block field, and 4 in the offset field
- 記憶體位址 0x0DB63 會對映到哪個快取區快?
    > 00001100101 10110 0111, which implies

### 4. 設採用全關聯式快取的計算機具有容量為216個位元組的以位元組定址的主記憶體以及64個區塊的快取，每個快取區塊內含32個位元組。
- 主記憶體中有多少個區塊?
    > $2^{16}/2^{5} = 2^{11}$
- 快取所見的記憶體位址格式為何?也就是標籤、區快與位移的欄位大小各若干?
    > 16 bit addresses with 11 bits in the tag field and 5 in the offset field
- 記憶體位址 0xF8C9 會對映到哪個快取區快?
    > 可以對應任何位置
### 7. 某2路集合關聯式快取內有4個集合。主記憶體中有2K個大小式8個位元組的區塊且以位元組定址。
- 表示主記憶體位址在用於快取時的格式。確實標示個欄位及其大小。
    > $2K * 2^{3} = 2^{14}$
- 計算由位址 0x8 至 0x33 並反覆3次的程式的命中率。可將命中率以分數表示。
    > $126/132 = 95.45\%$

### 10. 設有記憶體位址對應的字組大小是8位元的計算機。該計算機具有16位元組、區塊大小是4位元組的塊取。計算機於執行程式的過程存取了一些記憶體位置。設該計算機採用直接對映式塊取。快取所見的記憶體位址格式如下：
![](https://media.discordapp.net/attachments/791874005916450826/797070066726076436/unknown.png)
### 系統依照以下次序存取記憶體位址：0x6E、0xB9、0x17、0xE0、0x4E、0x4F、0x50、0x91、0xA8、0xA9、0xAB、0xAD、0x93與0x94。最先四次存取的記憶體位址已被載入下列的快取區塊中。(標籤的內容以二進行式表現，而快取的「內容」則不過式以位址存於該位置中)。
![](https://media.discordapp.net/attachments/791874005916450826/797071315558334465/IMG_20201225_120357.jpg?width=959&height=402)
- 若前四次存取都是錯失，上述整個記憶體存取序列的命中率是多少?
    | Address |                     Hit or Miss                     |
    | :-----: | :-------------------------------------------------: |
    |   6E    | Miss, brought into Block 3 with tag 0110 (as shown) |
    |   B9    | Miss, brought into Block 2 with tag 1011 (as shown) |
    |  0x6E   | Miss, brought into Block 3 with tag 0110 (as shown) |
    |  0xB9   | Miss, brought into Block 2 with tag 1011 (as shown) |
    |  0x17   | Miss. brought into Block 1 with tag 0001 (as shown) |
    |  0xE0   | Miss, brought into Block 0 with tag 1110 (as shown) |
    |  0x4E   |      Miss, brought into Block 3 with tag 0100       |
    |  0x4F   |                         Hit                         |
    |  0x50   |      Miss, brought into Block 0 with tag 0101       |
    |  0x91   |      Miss, brought into Block 0 with tag 1001       |
    |  0xA8   |      Miss, brought into Block 2 with tag 1010       |
    |  0xA9   |                         Hit                         |
    |  0xAB   |                         Hit                         |
    |  0xAD   |      Miss, brought into Block 3 with tag 1010       |
    |  0x93   |                         Hit                         |
    |  0x94   |      Miss, brought into Block 1 with tab 1001       |
    > 由上圖知道，有$4/14=28.6\%的機率會命中$
- 在最後一個位址存取之後，哪些記憶體區塊會存在快取中?
    > Block 0, with tag 1001, contains 0x90, 0x91, 0x92, 0x93<br />
    > Block 1, with tag 1001, contains 0x94, 0x95, 0x96, 0x97<br />
    > Block 2, with tag 1010, contains 0xA8, 0xA9, 0xAA, 0xAB<br />
    > Block 3, with tag 1010, contains 0xAC, 0xAD, 0xAE, 0xAF<br />

### 15. 設有容量4096位元組、區塊大小16位元組的直接對映式快取。若位址長32為位元組且快取開始為空，完成下表。(答案應以十六進數字表示。)若各個位址一所示次序存取，哪些存取會造成衝突(使才被寫入的區塊又被強制覆蓋掉)?
| 位址       |  標籤   | 快取中位址(區塊) | 區塊中位移 |
| :--------- | :-----: | :--------------: | :--------: |
| 0x0FF0FABA | 0x0FF0F |       0xAB       |    0xA     |
| 0x00000011 | 0x00000 |       0x01       |    0x1     |
| 0x0FFFFFFE | 0x0FFFF |       0xFF       |    0xE     |
| 0x23456719 | 0x23456 |       0x71       |    0x9     |
| 0xCAFEBABE | 0xCAFEB |       0xAB       |    0xE     |

### 18. 設某程序的頁表內含如下的項次。使用圖6.18中的格式，指出程序的各頁位於主記憶體中何處。
- ![](https://media.discordapp.net/attachments/791874005916450826/797075443156647936/unknown.png)
    > ![](https://media.discordapp.net/attachments/791874005916450826/797086595996057610/unknown.png?width=384&height=467)

### 21. 程序P有一以位元組定址的具有2項次的TLB的虛擬記憶體系統、一2路集合關聯式快取，以及一頁表。設快取區塊大小是8位元組、頁大小是16位元組。在下列系統中，主記憶體分成以字母代表的各個區塊。兩個區塊形成一個頁框。
![](https://media.discordapp.net/attachments/791874005916450826/797075823202533376/IMG_20201225_120432.jpg?width=688&height=467)
已知系統狀態如上，回答下述問題：
- 程序P的虛擬位址中的位元數若干? 並說明之
    > $2^3*2^4=2^7$
- 實體位址中的位元數若干? 並說明之
    > $2^2*2^4=2^6$
- 表示虛擬位址0x12在系統將之轉換為實體位址時使用的位址格式(指出各攔的名稱與大小)，並將之轉換成對應的實體位置(提示：將為只以二進制形式表示且將之劃分成恰當的欄位)說明這咧欄位如何用於轉換至對應的實體位址
    > 0x12 = 001(page field) 0010(offset), 
- 已知虛擬位址0x06會轉換成實體位址0x36。對實體位只表示其用以決定對應的快取位址時使用的格式(指出個欄位的名稱與大小)。說明如何經由這樣的格式決定實體位只0x36會對應到快取中的哪個位置(提示：將0x36以二進制形式表示，然後再劃分成適當的欄位)
    > 0x36 = 11(tag) 0(set) 110(offset),
- 已知虛擬位址0x19位於虛擬頁1的位移9處。說明這個位址如何轉譯成他的實體位只、以及數據如何存取。在說明應包含如何使用TLB、頁表、快取記憶體
    > 0x19 = 001(virutal page) 1001(offset), 

### 22. 一虛擬記憶體系統具有一個TLB、一個快取與一個頁表。假設：
```
TLB命中需時 5ns
快取命中需時 12ns
主記憶體快取需時 25ns
碟片存取需時 200ms (包括更新頁表、快取與TLB)
TLB命中率是 90%
快取命中率是 98%
頁錯誤率是 .001%
TLB或快取錯失時，存取所需的時間包刮TLB與/或快取更新，不過存取並不會重新開始
頁錯失時，頁由碟片中取得、執行所有的更新、不過存取會重新開始
所有存取都循序地發生 (不重疊、沒有平行的動作)
```
分別指出下列各種情形是否可能。若可能，說明存取所需數據耗時的時間。
- TLB命中、快取命中
    > $5ns(TLB)+12ns(cache)$
- TLB錯失、頁表命中、快取命中
    > $5ns(TLB)+25ns(page table)+12ns(cache)
- TLB錯失、頁表命中、快取錯失
    > $5ns(TLB)+25ns(page table)+12(cache)+25ns(main memory)$
- TLB錯失、頁表錯失、快取命中
    > 不可能
- TLB錯失、頁表錯失
    > $5ns(TLB)+25ns(page table)+200ns(disk)+5ns((TBL, again)+12ns(cache)$
