# 2주차 과제
* 1. VCS란 무엇인가

     버전관리 시스템(VCS, Version Control System)이란 파일 변화를 시간에 따라 기록했다가 나중에 특정 시점의 버전을 다시 불러올 수 있는 시스템을 의미합니다.

* 2. DVCS와 VCS의 차이점

     DVCS는 Git이 사용하고 있는 방식으로 파일들이 원격 저장소(서버, e.g. GitHub)와 클라이언트들의 각 로컬 컴퓨터에 분산되어 저장됩니다.

     클라이언트들의 로컬 컴퓨터에서 파일들을 1차적으로 저장하고, Github과 같은 원격 저장소에도 저장할 수 있습니다. 그림처럼 모든 파일들이 분산되어 저장되기 때문에 파일들이 삭제되는 일이 발생하더라도 다른 쪽(원격 저장소나 다른 클라이언트)에서 가져올 수 있기 때문에 쉽게 복구가 가능합니다.


     VCS는 파일 변화를 시간에 따라 기록했다가 나중에 특정 시점의 버전을 다시 꺼내올 수 있는 시스템이며
 
     파일의 버전이 어디서 파생되었는지 알기가 쉽지 않다.     
     실수로 파일을 삭제할 수도 있고 다른 파일에 덮어 씌우는 경우도 발생할 수 있다.
     어떤 파일이 진짜 최종 파일인지 판단하기 힘들다.

     파일이 많아지면 용량을 많이 차지한다

* 3. GIT을 이용하여 remote repository를 생성하고 git용 bash 로 새로 initialize한 local repository랑 연결하는 과정을 스크린샷과 함께 각 명령어의 자세한 설명을 작성하시오. 이때 브랜치명은 main으로 합니다.


     
     ![git_1](https://github.com/yuh2327015/programig-patern/assets/127164406/6383bc3d-f310-453b-9a72-58158319a85d)
     - git status  :  파일 상태 확인하기

     ![git_2](https://github.com/yuh2327015/programig-patern/assets/127164406/8acdf52a-d3a4-4c79-849d-d0ce766929b2)
     - git add .  :   작업 디렉토리(working directory) 상의 변경 내용을 스테이징 영역(staging area)에 추가하기 위해서 사용하는 Git 명령어입니다.
![git_3](https://github.com/yuh2327015/programig-patern/assets/127164406/1b0e0b21-6b56-4f4f-b170-74f278bb05ad)
![git4](https://github.com/yuh2327015/programig-patern/assets/127164406/01778c75-92bd-4eca-b612-9ba63099a388)
- git commit : commit을 함으로써 git에 저장을 한다. 또한 git에 저장을 함으로써 코드를 삭제, 변경하더라도 다시 이전의 상태로 되돌릴수가 있게 된다. 
![git5](https://github.com/yuh2327015/programig-patern/assets/127164406/bf4e2d16-1089-4d18-843c-6e2b3e7e76a2)
- git log  :  커밋 이력 상세 조회. 가장 최근의 커밋이 먼저 나오고 스페이스 바를 누르면 변경 이력이 하나씩 보여진다.

![git6](https://github.com/yuh2327015/programig-patern/assets/127164406/8d2df2d0-8811-4984-9402-862ae6d3392d)
![git7](https://github.com/yuh2327015/programig-patern/assets/127164406/2c777a63-6b5e-407f-8ab2-1d004e0ec79e)
![git8](https://github.com/yuh2327015/programig-patern/assets/127164406/d2d49e4c-5aca-4d96-88a4-950223640a7d)
![git9](https://github.com/yuh2327015/programig-patern/assets/127164406/e6c0b64b-f5aa-4194-bea2-003242ed0363)

     
* .gitignore 사용법과 작성방식 및 내용에 대해서 조사를 해 오시오.


  .gitignore 파일 생성: 프로젝트 루트 디렉토리에 .gitignore 파일을 생성합니다.

무시할 파일 또는 디렉토리 패턴 작성: .gitignore 파일에 무시할 파일 또는 디렉토리의 패턴을 작성합니다.

패턴 작성: 파일 또는 디렉토리의 경로나 확장자를 작성합니다. 이 때, 와일드카드(*)나 경로 구분자(/) 등을 사용하여 패턴을 지정합니다.

주석: 주석은 #으로 시작하며, 해당 줄은 무시됩니다. 주석을 사용하여 다른 개발자에게 파일을 무시하는 이유나 작성 규칙을 설명할 수 있습니다.

적용: .gitignore 파일을 작성한 후에는 Git이 해당 파일을 인식하도록 커밋해야 합니다.

* 5. ReadMe.md 파일에 사용된 Mark Down 표기법 에대해서 헤더/목록(숫자)/순서없는목록(ex>*) / 들여쓰기 / 코드블럭 / 수평선 /링크 / 이미지/ 강조 
에 대해 사용 방법을 정리해 오시오

