TODO
- [ ] 播放流式处理
- [ ] 本地鉴权
- [ ] 增加UI 界面
  - [x]   屏幕2.4 st7789
  - [x]   库 TFT-eSPI
- [ ] web 配置界面
# Esp32_VoiceChat_LLMs
esp32 based device, mainly used for voice chat with large language models

bilibili：https://www.bilibili.com/video/BV1Xv421r715/?spm_id_from=333.999.0.0&vd_source=e90851eaa96a26b2d252237f9312b9f6
# 硬件链接
主控 esp32wrover
按键
```c
#define key 33 //0
#define Addnoise 32
#define Minoise  26
```
麦克风 MSM261S4030H0R
```c
//mic pin
#define PIN_I2S_BCLK 4
#define PIN_I2S_LRC 12
#define PIN_I2S_DIN 34
```
功放 max98257
```c
#define I2S_DOUT 13 // DIN
#define I2S_BCLK 19 // BCLK
#define I2S_LRC 18  // LRC
```
# 一、platformio 安装
# 二、星火大模型注册，认证
选择个人认证就行
https://xinghuo.xfyun.cn/sparkapi
创建应用，
![image](https://github.com/lumang/Esp32_VoiceChat_LLMs/assets/9112945/ff98bccf-f25a-453a-bbbf-d2d6843b16b3)
选择接口，token 选择购买按钮 免费的
![image](https://github.com/lumang/Esp32_VoiceChat_LLMs/assets/9112945/603a5d4a-277d-404e-9642-eea64d4b5cd0)

# 配置Wi-Fi，
# 配置星火参数
![image](https://github.com/lumang/Esp32_VoiceChat_LLMs/assets/9112945/2d90036b-5a86-4e9c-9ac5-56c4f31998d5)

# 编译下载
```shell
rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:1
load:0x3fff0030,len:1344
load:0x40078000,len:13964
load:0x40080400,len:3600
entry 0x400805f0
Connecting to Ssid
..............
-- wifi connect success! --
IP address: 192.168.2.177
Free Heap: 183984
try to read from Tencent cloud
HTTP/1.1 200 OKServer: Werkzeug/3.0.1 Python/3.12.2Date: Thu, 14 Mar 2024 06:13:59 GMTContent-Type: text/html; charset=utf-8Content-Length: 329Connection: closews://spark-api.xf-yun.com/v3.1/chat?authorization&host=spark-api.xf-yun.comtry to read from Tencent cloud again
HTTP/1.1 200 OKServer: Werkzeug/3.0.1 Python/3.12.2Date: Thu, 14 Mar 2024 06:14:00 GMTContent-Type: text/html; charset=utf-8Content-Length: 316Connection: closews://ws-api.xfyun.cn/v2/iat?authorization==Thu%2C+14+Mar+2024+06%3A14%3A00+GMT&host=ws-api.xfyun.cn
```
# 测试
```shell
voice = 6 silence = 4
isread= 0
0 16.821444
voice = 6 silence = 5
Connected to server1!
xunfeiyun return message:
{"code":0,"message":"success","sid":"8e3b9a6c05a181802","data":{"result":{"sn":1,"ls":false,"bg":0,"ed":0,"vad":{"ws":[{"bg":22,"ed":116,"eg":38.35}]},"ws":[{"bg":35,"cw":[{"sc":0,"w":"唱歌"}]},{"bg":75,"cw":[{"sc":0,"w":"了"}]}]},"status":0}}
唱歌了
xunfeiyun return message:
{"code":0,"message":"success","sid":"e3b9a6c05a181802","data":{"result":{"ls":true,"bg":0,"ed":0,"ws":[{"bg":94,"cw":[{"sc":0,"w":"。"}]}],"sn":2},"status":2}}
唱歌了。
status == 2
Connnection1 Closed
```
