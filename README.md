![header](https://capsule-render.vercel.app/api?type=rounded&height=300&color=auto&text=스마트%20물류%20시스템&textBg=false&desc=아두이노를%20이용하여%20구현한%20스마트%20물류%20시스템&section=header&fontAlignY=50&animation=fadeIn&reversal=true&descAlignY=70)
# Arduino_Smart_Logistics_System
아두이노 스마트 물류시스템

## 개요
해당 프로젝트는 아두이노와 여러 센서들을 활용해서 가상의 물류 시스템을 만드는 것을 목표로 합니다.  
창고 내 물류 효율성을 높이며, 실시간 재고 관리를 지원 할 예정입니다.

- 개발 언어 : C, C# .NET 6.0  
- 개발 환경 : Arduino, Arduino IDE, Visual Studio 2022 IDE, Windows 11  
- 개발 기간 : 2024.04.09 ~ 2024.?.?  
## 기능
#### HW 기능
1. RFID 테그  
물품에 RFID 테그를 부착하여 물품의 정보를 담는다.

2. 무게 측정  
사용자가 물품의 무게를 측정하기 위해 사용한다.

3. 로봇팔  
무게 측정이 끝난 물품을 컨베이어 벨트로 운반한다.

4. 물품분류  
무게에 따라 물품을 어느 상자로 보낼지 분류한다.

5. 컨베이어 벨트  
물품을 저장상자에 운반시킨다.

#### SW 기능
1. 재고 관리 프로그램  
물품이 어느 상자에 담겼는지 보여주는 GUI 프로그램입니다.

2. 지도  
가상의 물류 창고와 가상의 로봇이 있다는 가정하에 창고내에서 로봇이 최단 거리를 구하는 가상의 지도 구현

## 구상도
<p align="center">
<img src="https://github.com/2daeeun/Arduino_Smart_Logistics_System/blob/README.md/img/임시_구상도_사진.png?raw=true">
</p>

## 프로토타입 
#### HW 프로토타입
<p align="center">
<img src="https://github.com/2daeeun/Arduino_Smart_Logistics_System/blob/README.md/img/HW_프로토타입.jpg?raw=true">
</p>

#### SW 프로토타입
<p align="center">
<img src="https://github.com/2daeeun/Arduino_Smart_Logistics_System/blob/README.md/img/SW_프로토타입.gif?raw=true">
</p>

## 시연 영상
<p align="center">
<img src="https://raw.githubusercontent.com/2daeeun/Arduino_Smart_Logistics_System/README.md/img/Black.png">
</p>

## 팀원
<table border="1">
    <tr>
        <td align="center"><a href="https://github.com/KimHyunJoon00"><img height="100px" width="100px" src="https://avatars.githubusercontent.com/u/127961477?v=4" alt="김현준 프로필"/></a></td>
        <td align="center"><a href="https://github.com/2daeeun"><img height="100px" width="100px" src="https://avatars.githubusercontent.com/u/55821132?v=4" alt="이대은 프로필"/></a></td>
    </tr>
    <tr>
        <td align="center">김현준</br>(HW 개발 및 팀장)</td>
        <td align="center">이대은</br>(SW 개발 및 PM)</td>
    </tr>
</table>

##### NOTE
* 중간 프로젝트 발표 자료 [[Link]](https://github.com/2daeeun/Arduino_Smart_Logistics_System/blob/docs/docs/4학년%201학기%205_ASAP%20프로젝트_구현_및_데모_%28최종%29.pdf)
* 중간 프로젝트 계획서 자료 [[Link]](https://github.com/2daeeun/Arduino_Smart_Logistics_System/blob/docs/docs/4학년%201학기%20최종보고서.pdf)
