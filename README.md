# 108Hw1
2 bit-counter
讀取資料"TNNNTT"字串,一次用fgets讀取一個值,將T或N轉為1或0存入outcome中,準備等下去做比較
程式初始預測為"0 0",和讀入的資料作比較,
如果一樣:
if "T"
  當預測值不為ST時值會加一
if "N"
  當預測值不為SN時值會減一
加減後會依值進行進位等調整,miss數會計算加一,每讀入一次,便作一次預測,結束時將miss數印出.





執行結果

![image](https://github.com/lin10901/108Hw1/blob/master/%E8%A8%BB%E8%A7%A3%202020-01-09%20164626.png)
