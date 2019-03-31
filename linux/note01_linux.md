root
linux

### 리눅스


### 하이퍼바이져
- H/W OS 간에 중간계층에 있음

### 우분투
- 구글이 안드로이드의 기반 OS를 우분투로 지정하면서 상승세를 탐
- 일반적으로는 레드햇 계열이 추천됨


### 쉘 프롬프트
- 형식: <ID>@<PC이름>:<경로><권한기호>
- 권한 기호 $ or #
	-- $: 유저
	-- #: root

### etc
- 리눅스 설정 등이 있는 폴더

### 폴더 구조
```
/
  /root
  /etc
  /home
    /user1
    /user2
    /user3
```

### 리눅스 배포판
- 리누스 토발즈
	Kernel

- Redhat(pkg: rpm)
	Fedora
	Redhat Enterprise
	CentOS
	Amazon Linux
	Suse Enterprise
	Open Suse

- Debian(pkg: deb)
	- Debian
	- Ubuntu(Canonical 사)


### 파일 시스템
- Windows: NTFS
- Linux: ext(다른 것도 쓸 수 있음)


### 장치 파일
- OS가 장치를 관리할 수 있도록 하는 특수한 파일

### 링크
- 하드 링크: 같은 파일에 대해 다른 이름을 부여하는 개념
	-- 데이터 블록에 동일한 곳을 가리킴
	-- link 카운트가 늘어남
(다른 파일 시스템에 있는 파일을 참조할 수 없음)

- 심볼릭 링크: 경로 정보를 갖고 있는 링크 방법 


### 명령어
- pwd: 현재 작업 디렉토리 경로
- mount: OS의 파일 시스템 정보
- alias: 명령어의 단축 별칭을 지정
(ex. alias rm='rm -i')
- 

### 명령어의 옵션
- 한문자로된 옵션: '-'
- 단어로된 옵션: '--'

### 명령어의 색션
- 1: 사용자 명령어
- 2: 커널 시스템 콜 API
- 3: C 라이브러리 API
- ...

### 다수 명령어를 한번에 순차적으로 시행하는 명령어: ; / &&
- &&: 앞의 명령어가 성공하면 뒤의 명령어를 시행
- ; : 앞의 명령어 성공과 상관 없이 명령어 시행

### EOF
- Windows: Ctrl + z
- Linux: Ctrl + d

### 표준 스트림
- stdin: 0,
- stdout: 1, 
(라인 버퍼를 사용하기에 '\n' 단위로 화면이 출력됨)
- stderr: 2, 
(버퍼링을 안씀 그냥 바로 화면에 출력됨)

### 파이프
- 왼쪽 명령어의 표준 출력을 오른쪽 명령어의 표준 입력으로 대체
(ex. cat text.txt | grep 'abc')

### 리다이렉션
- 1> or >: 표준 출력을 리다이렉션
(대상 파일을 0으로 만든 후 동작하기 때문에 <,>를 같은 파일에 대해 시행하는 것은 금지 ./a.out < tmp > tmp (X))
- 2>: 표준 에러를 리다이렉션
- 리다이렉션은 중첩되지 않는다 '1>&2 >'에서 앞과 뒤의 꺽쇠는 별개로 동작함
- 화면에 출력하고 싶지 않을 때 사용하는 널 디바이스
(ex. $ ..... > /dev/null)

### mkfifo
- 주로 IPC에 사용됨
- t2의 입력을 t1에서 출력
```
// t1
mkfifo myfifo
cat myfifo

//t2
cat > myfifo
```

### 인용 부호
- 큰 따옴표
	-- 공백, 개행 등을 그대로 보여줌
	-- $, \, ``를 제외한 기타 특수 문자들이 그냥 문자로 인식
	-- 큰 따옴표 출력을 위해서는 작은 따옴표 또는 백슬래시 사용
- 작은 따옴표
	-- 모든 와일드 카드를 그냥 문자로 인식
	-- 작은 따옴표 출력을 위해서는 큰 따옴표 또는 백슬래시 사용
- 특수 문자는 가장 외부에 있는 따옴표 기준으로 작동함

### 권한
- 권한 변경은 소유자와 root만 가능
- file
	-- r: 내용 확인
	-- w: 내용 수정, 이동, 삭제(directory에 w권한필)
	-- x: 실행
- directory
	-- r: ls 시행
	-- w: 파일 생성 삭제
	-- x: cd로 접근
- umask
	-- creation mask
- +, -, = 앞에 a를 쓰는 것과 안쓰는 것의 차이
	-- a+r: 모든 사용자에 대해 r권한 추가
	-- +r: creation mask가 설정되지 않은 사용자에 대해 r 권한 추가
- 쉽표를 통해 여러개를 연달아 쓸 수 있음
($ chmod +r,+w file.txt)

### su / sudo: 사용자 변경 / 다른 사용자로 명령어 실행
- 사용자 환경 로드와 같이 변경: $ su -l
- sudo로 passwd할 때와 일반 사용자가 passwd할 때 묻는 정보량이 다름
	

### 명령을 백그라운드로 실행: &
- 포그라운드와 백그라운드의 차이: 사용자 입력을 받는지 안받는지 여부
- 예시: $ ./a.out &
- 프로세스 일시 정지: Ctrl + z

### 쉘 변수 / 환경 변수
- 쉘 변수는 자식 쉘로 전달되지 않음
- 환경 변수를 설정하는 export 명령어: $ export <변수명>=<값>
- 특수 변수
	-- $: 쉘의 PID
	-- ?: 최근 실행한 명령어의 종료 상태

- 로그인 쉘 세션용 시작 파일
	1. /etc/profile: 모든 사용자에게 적용되는 환경
	(전역 설정이기에 안 건드는 것을 권장)
	2. ~/.bash_profile: 개인 사용자의 환경(1을 무시 또는 확장)
	3. ~/.bash_login: 2가 없으면 이 파일을 적용
	4. ~/.profile: 2, 3이 모두 없으면 bash가 이 파일을 적용

- 수정된 스크립트의 적용 ex: $ source ~/.profile

### vim 꿀팁
- <#>yy: #줄 복사
- :x (:wq와 동일)
- :%y (문서 전체 복사)


### vim 문자열 치환
- :<시작줄>,<끝줄>s/찾을패턴/바꿀스트링/옵션
	-- 시작 끝 대신 '%'를 쓰면 문서 전체를 대상
(상대 범위 ex: :.,.+3s/p1/p2)
- 옵션:
	-- g(global): 한줄에 여러 패턴이 나오면 모두 바꿈
	-- i(ignore case): 대소문자 구분 없이 바꿈
	-- c(confirm): 바꿀지 말지를 물어본 뒤 바꿈

### 정규표현식
- 특정한 규칙을 가진 문자열의 집합을 표현하는 데 사용하는 형식 언어
- 확장 정규 표현식: (){}?+|
(grep 사용시 -E 옵션 필요)
- POSIX 표준 보다는 확장 정규표현식을 권장


### 텍스트 검색 명령어 grep
- 옵션:
	-- -c: 패턴이 일치하는 행의 개수 출력
	-- -n: 일치하는 행 번호 함께 출력
	-- -i: 대소문자 구분 안 함
	-- -l: 패턴이 포함된 파일의 이름 출력
	-- -L: 패턴이 포함되지 않는 파일의 이름 출력
	-- -r: 하위 디렉토리의 파일까지 출력
	-- -w: 패턴이 단어로 일치되는 행만 출력
	-- -v: 포함하지 않는라인 출력
- 특수 기호
	-- .: 임의의 한 문자로 대치, 중복 사용 가능, 백슬러시와 함께 쓰면 단순 문자
	-- ^: 문자열, 행의 시작을 의미 
	-- $: 문자열, 행의 끝을 의미

### grep의 대체품
- ag
- rg(ripgrep)

### 패키지 관리
- deb, rpm 등을 직접 다운받아서 설치하면 의존성 문제를 해결하기 어려움
- 설치된 패키지 목록 확인
	-- 데비안: dpkg --list
	-- 레드햇: rpm -qa
- 설치 여부 확인
	-- 데비안: dpkg --status <패키지 네임>
	-- 레드햇: rpm -q <패키지 네임>

### tar
- gzip의 한계: 여러 개의 파일을 한번에 압축할 수 없음
- 모드:
	-- c: 파일, 디렉토리 목록에서 아카이브 생성
	-- x: 아카이브 해제
	-- r: 아카이브 끝에 지정된 경로명 덧붙이기
	-- t: 아카이브 내용 보기
- 옵션:
	-- f: 파일 이름
	-- v: 처리 과정을 표준 출력
	-- z: gzip을 통해 압축(확장자로 tar.gz 또는 tgz를 사용)
	-- j: bzip로 압축
- 사용예:
	$ tar cvfz

### find
- 사용법: $ find <경로> <표현식>
- 테스트:
	-name <패턴>
	-iname <패턴>
	-size n
	-type x
	-empty
	-perm mode
- 연산자
	- -a(-and):
	- -o(-or):
	- -!(-not):
	- (): 괄호 앞에 \가 필요하며 앞 뒤에 공백이 필요

- 액션
	- -print: 
	- -ls: 
	- -delete:
	- -quit: 

- 사용자 지정 액션
	-- -exec <명령어> \{ \} \;
	-- ex) $ find . -type f -name '*.o' -exec rm \{ \} \;
	-- ex) $ find . -type f -name '*.o' -exec cp \{\} /home/proj/ \;

### 주의
- Git Repo에 절대로 '절대 경로'를 올리면 안됨

