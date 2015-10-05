책 그대로 배끼면서 연습!

우분투 환경에서
C언어로 배우는 리눅스 프로그래밍
=====
> 이이오 준 지음, 김성재 옮김, 한빛미디어 출판

-----------------------------------------------------

> 프로그램 소스를 분할하는 이유

- 프로그램의 구조화

프로그램 전체를 각각의 파일로 나누면 프로그램 전체의 구성을 파악하기 쉬워짐.

- 빌드 시간 단축

일반적으로 컴파일 처리에는 어느 정도 시간이 걸림. 하지만 앞에서 본 분할 컴파일의 예처럼 소스 코드를 나눠두면 일부분을 수정했을 때 그 파일만 다시 컴파일하면 됨.
새로 컴파일된 오브젝트 파일을 링크하면 전체를 갱신할 수 있기 때문임.

- 여러 개발자에 의한 개발

동시에 여러 개발자가 개발하기 쉬운 장점이 있음.

- 유지보수 향상 대책

프로그램을 나누고 구조화한 결과 플랫폼에 의존하는 부분을 잘라내 격리하는 일이 자주 일어남.  분할하면 유지보수가 쉬워짐. 다른 플랫폼으로 이식할 때도 분할한 부분을 중심으로 검토하면 됨.

--------

> make의 이용

- 배치파일의 문제점

유감스럽게도 list0321.sh는 분할 컴파일의 장점을 희생시키는 중대한 문제점이 있음. list0321.sh 로 일괄처리하면 모든 소스 코드를 재컴파일해 버림. 규모가 크고 복잡한 프로그램이면 개발 효율이 저하됨.

- make

*분할 컴파일의 장점도 살리면서 어떻게든 빌드를 자동화 할 수 있게 하는 도구가 바로 make!*
make에는 각 파일 사이의 의존성을 파악하고 파일의 타임스탬프를 비교해 다시 생성할 필요가 있는지 판단하는 기능이 있음.

- makefile

'소스 데이터로부터 결과물이 (어떤 수단으로) 만들어진다'는 규칙을 파일에 작성해 두면 make는 파일을 해석해 순차적으로 처리함. 이 규칙을 작성한 파일을 'makefile'이라고
하고 기본 메이크파일의 이름은 Makefile. make -f filename처럼 -f 옵션을 주고 이름을 지정하면 다른 이름으로 메이크파일을 지정할 수 있음.

메이크파일에는 결과물과 소스 데이터와의 관계를 '결과물: 소스 데이터'처럼 콜론(:)으로 연결해 작성. 하나의 결과물에 여러개의 소스 데이터를 연결할 수 있다. 그리고 다음
줄에는 변환 수단을 작성. 구체적으로는 터미널에 입력해야 하는 명령 또는 배치파일에 기재한 명령을 작성. 이때 명령은 반드시 '탭tab'으로 들여쓰기 해서 작성해야 함.

- make의 동작

touch list0311A.c로 소스 코드를 수정한 것처럼 한 후, 다시 make 명령을 실행하면 list0311B.c는 수정하지 않았으므로 재컴파일 하지 않음.
make를 이용하면 분할 컴파일의 장점을 살릴 수 있음.

*touch는파일의 timestamp를 현재 시간으로 새로 고치는 명령. 이 조작으로 어떤 수정을 했다는 것을 모의적으로 처리. 만약 파일이 없으면 빈 파일을 생성.*

> 다양한 make의 기능

make의 개념은 아주 중요함. 특히 make에서 사용되는 매크로나 내부 매크로는 범용적으로 이용되므로 익숙해 져야함.

- 매크로의 자동 변수

매크로의 정의와 자동 변수(automatic variables). 간단히 말해 매크로는 '치환하는 기능'. 또한, 자동 변수는 내부적으로 정의되어 자동으로 치환되는 더 범용적인 매크로라고
생각할 수 있음.

$^는 의존 관계가 있는 모든 파일을 나타냄. 여기서는 $(OBJS)가 그에 해당. 한편 $@는 타깃 파일을 나타내며 마찬가지로 $(TARGET)에 해당. make 내부에 미리 정의된 매크로
목록을 보려면 터미널에서 make -p 명령을 실행하면 되지만, 이때 내부 매크로는 표시하지 않음. 

- 그 밖의 기능

암묵적인 규칙의 추가, 더미 타깃, 명령 삽입 등 그 밖에 자주 이용되는 기능은 더미 타깃(Dummy target). 보통 타깃과 달리 더미 타깃은 의존하는 파일이 없고 타깃 파일로 생성되지 않음. make를 실행할 때 타깃을 지정할 수 있는 점을 이용해 따로 처리하고자 하는 명령을 더미 타깃으로 작성하는 방법을 자주 이용함.

> make의 다양한 활용법

make 명령은 프로그래밍 이외의 분야에도 활용가능. 프로젝트를 구성하는 파일 사이에 어떤 의존성이 있고 원본 데이터에 변경이 가해졌을 때, 필요한 최소한의 수정만 하면 되는 경우 사용. 그 밖에 수치 데이터를 스크립트로 처리해 그래프 만들기, 텍스트 데이터를 데이터 마이닝 도구로 처리해 문서로 정리하기 등..

-----

> 라이브러리

'바퀴의 재발명은 피하라' 그 자산이란 소프트웨어 라이브러리.

- 다양한 라이브러리와 API
 
과학기술계산, 데이터베이스, 유저 인터페이스, 다양한 기기로의 접근 등에 사용되는 각양각색의 라이브러리 존재.

이런 라이브러리의 기능은 API(Application Program Interface)를 통해 사용가능. 

- 라이브러리와의 링크

라이브러리를 이용한 프로그램은 어떤 오브젝트 코드로 컴파일되는 것일까? 라이브러리에 의존하는 프로그램은 시스템에 필요한 라이브러리가 설치되지 않으면 동작하지 않음.
실제로 실행될 때는 라이브러리가 제공하는 코드와 결합(링크)해야 비로소 올바른 프로그램 코드가 되어 프로그래머의 의도대로 동작.

오브젝트 코드와 라이브러리를 결합하는 방법에 따라 정적(static) 라이브러리와 공유(shared) 라이브러리로 나뉨. 다시 공유 라이브러리는 일반적인 동적링크(dynamic link)
와 실행 시 필요에 따라 라이브러리 코드를 메모리에 로드하는 동적 로드(dynamic load)로 나뉨.

- 정적 라이브러리와 공유 라이브러리

정적 라이브러리를 사용할 때는 프로그램 빌드 시에 라이브러리가 제공하는 코드를 실행 파일에 넣음. 이 방식의 장점은 시스템 환경이 변해도 어플리케이션에 아무런 영향이
없고, 완성된 어플리케이션을 안정적으로 사용할 수 있음. 반면에 사용하는 모든 오브젝트 코드를 실행 파일에 내장하므로 메모리에 로드되는 어플리케이션 코드 크기가 커짐. 

공유 라이브러리는 이런 단점 해결. '공유'란 어떤 라이브러리가 제공하는 기능을 다른 어플리케이션에서 사용하고 싶을 때 라이브러리 코드를 메모리에 하나만 두고 각 어플리케이션에서 공유하는 것을 가리킴.

라이브러리 코드와 어플리케이션의 코드가 실행될 때 메모리에 로드되는 시점에 비로소 결합. 즉, 라이브러리를 이용하는 어플리케이션에는 '호출할 라이브러리 함수'의 정보만 들어있음.

- 동적 로드에 의한 어플리케이션의 확장

더욱 자유도가 높은 라이브러리 활용법은 동적 로드. 동적 링크 방식에서는 어플리케이션을 실행하면 실행 파일과 관련된 라이브러리 코드를 모두 메모리에 읽어들여 호출 관계를 조정한 다음 어플리케이션이 실행됨. 

동적 로드에서는 프로그램 내부에서 라이브러리를 로드함. 어느 라이브러리의 어느 함수를 이용할지는 프로그램의 동작 상황에 따라 변할 수 있음. 대다수 어플리케이션에서 자주 이용되는 플러그인에 의한 기능 확장은 동적 로드를 이용해 구현.

- 라이브러리의 의존성

라이브러리의 의존성을 확인하는 명령 ldd가 있다. ldd를 실행하면 그 어플리케이션이 이용하는 라이브러리를 보여줌.

> 헤더 파일의 역할

- 프리프로세서의 동작

컴파일러 드라이버인 gcc는 몇몇 도구를 호출해 C 프로그램 빌드를 진행함. 옵션 -E를 사용하면

```
컴파일과 링크와 실행 파일 만들기
1. 프리프로세서에 의한 파일 포함과 매크로 처리
2. 어셈블리 코드로 컴파일하고 어셈블 과정을 거쳐 오브젝트 파일로 변환
3. 오브젝트 파일 결합과 라이브러리 링크
```

위 과정중 1단계에서 중단하고 결과를 표준 출력으로 보낸 후 처리를 종료.
이 단계에서 #으로 시작되는 줄은 주석으로 처리.

포함할 파일을 어디에서 찾아오느냐의 차이점.
"..." (인용부호)로 지정하면 소스파일이 있는 디렉터리를 먼저 찾고, <...>로 지정하면 시스템이 준비한 디렉터리를 먼저 찾음.

> 사전으로서의 헤더 파일

- 함수 프로토타입 선언

list0333A.c	list0333B.c	list0333C.c 를 진행하면서

함수가 어떤 인수를 받고 어떤 형의 반환 값을 돌려줄지 개별적으로 작성 어려움. 또한 외부 파일에서 정의되는 구조체와 새롭게 정의되는 형을 이용할 때도 있음.
따라서 이런 정의를 모아둔 파일을 참조할 수밖에 없는 상태가 될 것임. 이것이 바로 헤더 파일.

헤더 파일의 함수 프로토타입 선언에 맞게 프로그래밍해야 하며 적절한 라이브러리의 링크를 지정해야 함.

- 라이브러리가 제공하는 함수 목록

헤더 파일을 보기만 해도 라이브러리의 사용법을 제대로 알 수 있음. 물론 각각의 API를 어떻게 사용하면 좋을지는 라이브러리에 첨부된 문서를 읽어야 함.

- G_BEGIN_DECLS란?

gstring.h 에서 사용되는 G_BEGIN_DECLS는 무엇을 정의?? /usr/include/glib-2.0/glib/gmacros.h에 다음처럼 정의.

```
/* Guard C code in headers, while including them from C++ */
#ifdef	__cplusplus
# define G_BEGIN_DECLS	extern "C" {
# define G_END_DECLS	}
#else
# define G_BEGIN_DECLS
# define G_END_DECLS
#endif
```

이 정의는 C 프로그래밍에서는 의미가 없음. 즉 __cplusplus가 정의되어 있지 않으면 공백으로 변환되어 버림.

이 코드는 라이브러리화했을 때 의미가 있음. C++ 에서 이용할 때는 이 매크로에 의미가 생김.
C++에서 C언어 코드를 이용할 때는 extern "C" {...}로 에워싸 C언어 함수임을 명시해야 함.
하지만 C언어에서는 불필요. 코드를 이용하는 언어에 따라 똑똑하게 전환하는 구조가 G_BEGIN_DECLS ... G_END_DECLS 임.

- 구조체의 확인

헤더 파일에 작성되는 정의는 함수의 프로토타입 뿐만 아니라 라이브러리에서 활용되는 구조체의 정의도 작성됨.

```
$ cat /usr/include/libio.h | less
```

로 확인해 보면 파일조작에 필요한 파일 디스크립터 구조체의 실체는 이렇게 정의되어 있다는 것을 알 수 있음. C프로그래밍 입문서에는 파일 디스크립터의
포인터 형태로 자주 보이는데, 헤더 파일을 조사하면 그 실체를 정확히 확인할 수 있음.

-----

###프로그램의 이식성

라이브러리를 활용해서 프로그래밍 할 때 주의할 점! '이식성'문제.

이식성은 시스템 환경이 바뀌어도 소프트웨어를 빌드할 수 있고 적절한 동작을 보증하는 것 혹은 그렇게 하기 위한 배려를 말함. 
다른 환경으로의 이식, OS를 넘어선 소프트웨어의 동작을 보증한다는 의미가 있으며 포터빌리티(Portability)라고도 함.

개발한 프로그램을 가능한 많은 사용자가 사용하게 하려면 프로그램의 이식성을 확보하고 가능한 한 많은 플랫폼에서 동작할 수 있어야 함.

> 플랫폼과 환경설정에 의한 차이

- OS에 의한 차이

플랫폼이 달라지면 시스템의 구조가 달라지는 것은 피할 수 없음. 마찬가지로 하드웨어가 달라지면 시스템의 동작도 달라짐. 

- 환경설정에 의한 차이

이식성을 신경쓰지 않은 채 배포되는 어플리케이션에는 의존하는 미들웨어와 라이브러리도 특정한 버전이 지정되어 있어, 새로운 버전에서 문제가 생기거나 혹은 반대로 최신 버전 라이브러리를 사용해야만 동작하는 등 환경구축 자체가 어려울 때도 있음.

> 차이를 극복하는 방법

- 소스코드에서 대처할 문제

	1. CPU 아키텍처 차이 : Big endian인지 little endian인지, 64bit인지 32bit인지, 그 이하 bit인지 등 비트를 직접 조작하는 코드를 작성할 때에는 주의!
	2. 라이브러리의 존재 : 해초에 활용할 라이브러리가 준비됬는지, 라이브러리의 버전은 적절하고 호출하는 함수의 시그니처가 맞는지, 구조체의 멤버 구성이 바뀌지 않았는지 등에 주의!
	3. C컴파일러 고유의 기능 : gcc 자체가 다양한 플랫폼을 지원하고 크로스 컴파일러 환경도 갖추고 있으므로 '컴파일러는 gcc를 사용하자' 라는 규칙만으로 해결되는 때도 있지만 gcc 이외의 컴파일러를 사용할 때는 각각 고유의 기능을 사용하고 있는지 이식할 수 있는지 주의!

- 매크로의 이용

플랫폰에 고유하게 정의되는 매크로를 이용해 컴파일할 코드를 전환하는 방법 활용. 이른바 조건부 컴파일 기능을 이용.

```
\#if defined(WIN32)
...
(windows 용 source code)
\#elif defined(linux)
...
(linux 용 source code)
...
```

\#if defined(WIN)는 \#ifdef 디렉티브를 사용해 \#ifdef WIN32라고 하기도 함. 윈도우 용 코드를 에워사는 데는 WIN32나\_\_WIN32\_\_ 등의 심볼이 자주 사용.

- 시스템에서 정의되는 매크로

```
$ echo | cpp -dM | less
```

로 표준입력을 더미로 사용하면 gcc 매뉴얼에 따라 사전 정의된 매크로(predefined macros) 목록을 볼 수 있음.

- 이식성을 높이는 설계

대다수 CPU architecture 를 지원하는 소프트웨어라면 리눅스 운영체제 자체를 빼놓을 수 없음.
플랫폼에 의존적인 부분을 가능한 한 분리해 설계하는 것이 소프트웨어의 이식성을 높이는 요령.

> Autotoolset

단순한 파일 구성이라면 몰라도 파일 수가 많아지면 Makefile을 기술하기 번거로움. 그래서 이식성을 확보하는 도구로 Autotoolset 사용.

- 반자동 빌드 과정

Autotoolset에 따른 절차의 특징은 configure 스크립트라고 불리는 스크립트가 소프트웨어를 구축하는 환경의 정보를 자동으로 수집하고 그 결과를 이용해 환경에 맞는 Makefile을 자동으로 만들어준다는 점. 이전에는 GNU Autotools라 불림.

> configure 스크립트

> Autotoolset을 이용한 개발 준비

list0432.c 를 작성하고 Makefile.am	configure.in(추후에 configure.ac로 수정하라고 warning 뜸) 작성.
그리고 aclocal, autoconf, automake 순서로 명령 실행.

automake 실행 시에 다양한 오류 메시지가 출력됨. 오류를 억제하려면 '-a' 옵션 사용. 이 옵션은 없는 파일을 자동으로 추가.
단, 패키지 제작자의 정보를 기재하는 AUTHORS, 프로그램 수정 이력을 기록하는 ChangeLog, 패키지에 관한 신착 정보를 기재하는 NEWS, 패키지에 관한 기본적인 정보를 기재하는 README 네가지는 -a 옵션을 사용해도 자동으로 만들어 주지 않음.

```
$ touch AUTHORS ChangeLog NEWS README
```

위처럼 빈 파일을 만들어 다시 automake 실행.		./configure 를 입력해 스크립트를 실행하고 Makefile이 작성됬는지 확인.

> CMake의 활용

- 다시보는 분할 컴파일

CMake의 설정 파일은 CMakeLists.txt . CMakeLists.txt 의 두번재 줄은 프로젝트를 정의하는 내용.
add_executable()은 실행 파일과 그 소스 파일을 가리킴. 여기서는 실행 파일이 list0431이며, 그 소스파일은 list0431main.c, list0431A.c, list0431B.c를 가리킴.

	1. cmake 명령으로 Makefile을 작성
	2. make 명령으로 실행 형식을 빌드

cmake의 옵션을 지정하면 일반적인 Makefile이 아니라, 통합 개발 환경용 프로젝트 파일도 작성가능.

-----

### 라이브러리의 특징과 활용 시 주의점

#####외부 코드 이용의 실제

C프로그래밍에서는 라이브러리로 제공되는 외부코드를 능숙하게 활용해 효율적으로 프로그래밍을 진행할 수 있는지에 따라 생산성이 크게 달라짐.
실제로 라이브러리의 코드는 어떻게 이용???

> 라이브러리와의 결합

우선 라이브러리로 제공되는 함수가 C프로그램에서 어떻게 호출되는지 그 실체를 확인하자.

- 외부코드의 이용

list0511.c 에서는 표준 라이브러리에 포함된 printf()를 이용해 메시지를 출력.

```
$ gcc -S -fno-builtin list0511.c
```

gcc 옵션으로 -S 옵션을 지정하면 같은 디렉터리에 list0511.s 라는 어셈블리어 코드 파일이 만들어짐.

_gcc 에서 printf는 빌트인 함수로 취급되고 표준으로는 puts로 변환됨. 따라서 이 경우 -fno-builtin 옵션을 이용해 변환은 막고 있음._

- 호출관계의 해결

실제로 호출되어 프로그램 일부가 되는 코드는 라이브러리로 시스템에 저장된 코드임.
단편적인 코드를 연결하는 명령이 링커 ld. 보통은 컴파일러 드라이버인 gcc에서 호출되므로 개발자가 신경쓸 일은 별로 없음.
하지만 이 과정을 거쳐야 비로소 실행 파일이 만들어지는 만큼 아주 중요한 과정.

> 정적 링크와 동적 링크

- 정적 라이브러리

기본적인 라이브러리의 형태는 정적 라이브러리라고 불리는 형식. 이들은 이미 컴파일된 오브젝트 코드를 재사용할 수 있는 형태로 모아놓은 것.
관습적으로 확장자는 .a 가 붙어있음.

리눅스 등 일반적인 유닉스 계열 OS에서는 /lib이나 /usr/lib, /usr/local/lib 디렉터리에 저장됨.
링커는 이들 라이브러리를 오브젝트 코드에 결합. 이때가 돼서야 드디어 외부 코드의 참조 관계가 해결됨.
앞의 예로 보면 call print로 호출되는 곳의 주소가 이 시점에 결정되고 실행 파일로써 완전해짐.

- 정적 링크의 단점

정적 라이브러리를 이용하는 방법은 아주 단순. 라이브러리 이용 모델도 이해하기 쉬움.

실행 파일에 라이브러리의 코드를 내장하는 방식의 단점은 생성되는 실행 파일의 크기가 커진다는 것.
gcc는 기본적으로 정적이 아닌 동적 링크를 이용하므로 -static 옵션을 붙여야 정적 링크를 이용함.

```
$ gcc list0511.c -o list0511
$ gcc list0511.c -o list0511static -static
$ ls -l list0511 list0511static
```
으로 생성된 파일의 크기를 비교하면 실제로 80배에 가까운 크기로 커짐.

- 공유 라이브러리

앞에서 본 /usr/lib/libc.a 같은 표준 라이브러리는 다양한 어플리케이션에서 사용됨. 그런 라이브러리가 따로따로 정적으로 링크됨으로써 같은 코드가 메모리에 몇 개씩 존재하는 상황은 낭비.

그래서 생각해낸 라이브러리 형식이 공유 라이브러리이며, 쉐어드 라이브러리(shared library)라고도 불린다. 공유 라이브러리는 'Shared Object'의 머리글자에서 따온 .so라는 확장자를 가진 파일로 저장됨. (실제로는 더 자세한 파일 명명규칙으로 된 실체에 대한 링크가 버전 관리 장치에서 준비됨.)

- 동적 링크

확실히 라이브러리를 ㅍ로그램 빌드 시에 결합할 수 없은데, 그것을 구현하는 것이 동적 링크.
공유 라이브러리 방식에서는 실행 파일이 빌드된 단계에서 호출할 라이브러리의 주소를 확정할 수 없음.
프로그램은 실행되기 직전에 ld.so 혹은 ld-linux.so 라는 동적 링커로 라이브러리에 링크되고 나서야 실행될 수 있음.
이것을 정적 링크에 대한 동적 링크라고 함.

> 동적 로드

- 동적 로드

프로그램이 로드되어 코드가 동작하기 시작한 후라도 일부 코드는 링크가 완결하지 않는 경우도 있음. 링크는 고사하고 아직 메모리에 로드되지 않았을지도 모름.
동적 로드에 의한 외부 함수 이용은 다음 과정으로 구현
```
1. dlopen()으로 대상 오브젝트 파일을 오픈
2. dlsym()으로 그 오브젝트 파일에서 실행하고 싶은 함수의 포인터를 얻음.
3. 함수의 포인터가 가리키는 코드를 호출
```

list0513.c 

이 메인 프로그램에서 호출되는 서브프로그램에는 함수 function()이 포함.
```
$ gcc list0513.c -o list0513 -ldl
```
이 프로그램은 일반 컴파일 절차로 충분. 단, dlopen() 등을 이용하려면 libdl을 링크, 즉 -ldl 옵션을 붙여 컴파일 해야함. 또한, 본체 프로그램에 정의된 함수나 변수에 동적 로드로 링크되는 코드로부터 액세스하고 싶을 때는 -rdynamic 옵션을 붙여 심볼을 공개해야함.

list0513dl.c

동적으로 로드되는 소스 코드는 다음처럼 컴파일 해야함. 
```
$ gcc list0513dl.c -fPIC -shared -o list0513.so
```
재배치 가능한 코드를 생성하는 -fPIC(위치 독립 코드(position independent code)) 옵션을 붙이는 것과 -shared 옵션을 붙여 공유 라이브러리로 만드는 것이 포인트.

동적으로 로드된 함수가 바르게 실행된 것이 맞는지 확인하려면 list0513dl.c 을 수정하고 다시 컴파일하고 다시 실행시켜 확인.

- 동적 로드의 응용

동적 로드를 잘 활용하면 플러그인이나 애드온이라고 불리는 확장 기능으로 기능을 계속 추가 할 수 있는 어플리케이션을 설계할 수 있음.
동적 로드를 사용하면 본체 프로그램을 재컴파일하지 않고 새로운 기능을 갖춘 모듈을 동적으로 로드하고 링크해서 확장 기능을 추가할 수 있음.

서버 어플리케이션처럼 항상 동작해야 하는 어플리케이션에서도 동적 로드를 이용할 수 있음.
메모리에 로드되어 동적으로 링크된 모듈을 언로드하고 새로 다른 모듈을 리로드함으로써 어플리케이션의 동작을 중단하지 않고 실제 처리내용을 변경할 수도 있음.

##### 라이브러리

> 라이브러리의 더 많은 활용

- 라이브러리 찾는 방법

[libxml 프로젝트 웹사이트](http://xmlsoft.org/)

또한 이미 필요한 라이브러리 패키지가 우분투용으로 있을 수도 있음. 우분투 소프트웨어 센터의 '개발자 도구' 카테고리를 점검하자.
이 카테고리에는 '라이브러리'라는 서브카테고리가 있음.

- 라이브러리를 찾았다면

쓸만한 라이브러리를 발견해서 설치했다면 사용법 확인!

우선 헤더 파일을 찾아 라이브러리에서 이용하는 함수의 프로토타입이 나열된 부분에 간단한 주석 정도는 기록되어 있을 것.
또한, 데이터 교환에 사용하는 구조체에도 각 멤버가 무엇을 의미하는지 주석확인.

> 라이브러리 이용 시의 함정

- API 변경

라이브러리의 버전이 바뀌었을 때 이미 컴파일된 실행 파일도 동작하지 않게 될까??? 실행 시에 링크할 공유 라이브러리에서 하위 호환성을 확보하는 soname이라는 구조가 마련되 있음. 라이브러리를 업데이트했을 때 soname 구조를 활용해 정합성을 유지하려면 관리자 권한으로 ldconfig를 실행해야 함.

- 심볼 확인

라이브러리가 제공하는 함수나 데이터는 헤더 파일의 프로토타입 선언과 구조체의 정의로 확인가능. 그리고 안을 들여다보면 실체를 확인가능.
라이브러리에서 이용할 수 있는 심볼은 nm 명령을 사용해 확인 가능. 예를 들면,
```
$ nm /usr/lib/libdl.a
```
을 사용해 출력된 내용을 확인하면 라이브러리 libdl.a는 dlopen.o나 dlclose.o와 같은 여러 오브젝트 파일로 구성된다는 사실 확인 가능.

- 메모리 관리와 데이터 다루기

한 가지 더 주의해야 할 점은 라이브러리에서 이용하는 데이터가 메모리상에 어떻게 배치되는 가이다.
복잡한 데이터를 구조체로 전달할 때는 참조에 의한 전달인지, 그렇지 않으면 복사가 발생하는지 등 여러가지로 주의를 기울여야 함.
이런 점은 인터페이스를 보기만 해선 알 수 없으며 메모리 누수(Leak)나 댕글링 포인터(아무 곳에서도 참조되지 않는 메모리가 계속 증가해 시스템 리소스를 압박하는 버그를 메모리 누수, 해제된 메모리 참조 등 부적절한 포인터 참조 버그) 등 디버그 하기 어려운 버그의 온상이 되기 쉬우므로 주의!

##### 스코프와 이름 공간

스코프는 변수나 함수 등의 심볼이 유요한 범위. 시시한 버그가 들어가지 않게 스코프를 정확히 인식하는 것은 중요.

> 변수와 심볼의 유효범위

C프로그램에서도 가장 단순한 스코프는 프로그램 코드에서 {}으로 에워싼 범위일 것.

- 변수의 스코프

> 들여쓰기와 스코프

C프로그램에서는 스코프 단위를 {}로 에워싸 표현. 이것은 if문이나 for문처럼 제어구조를 나타내는 스코프도 마찬가지. 대부분의 프로그래밍 언어에는 이처럼 스코프를 명시적으로 나타내는 문서 구조가 있음. {} 기호 대신 BEGIN, END 같은 예약어를 제공하는 언어도 있음.

그런데 세상에는 아주 드물게 들여 쓰기로 스코프를 나타내는 언어도 있음. 웹 어플리케이션이나 프로그램 실행 스크립트 인스톨러 등에서 자주 이용되는 파이썬은 들여쓰기로 스코프를 나타냄.

- 심볼의 스코프

list0531C.c

변수 a, b를 약간 다르게 취급. 모두 전역변수로 선언되었지만, 한쪽은 static이라는 키워드.

컴파일해서 생성된 오브젝트 파일을 nm으로 살펴보면
```
$ nm list0531C.o
$ nm -g list0531C.o
```

nm\_list0531C\_o\_file, nm\_-g\_list0531C\_o\_file 두개의 파일에 결과물을 저장하였음. nm의 옵션 중 외부에 공개되는 심볼만 출력해주는 옵션 -g

b는 단순한 '데이터 섹션에 있는 심볼' 임에 반해 C는 공통 심볼임.

> 파일 단위 관리

이 스코프 관리는 라이브러리 이용이나 분산 개발에서 꼭 필요한 기술.

- 이름 충돌

list0532A.c	list0532B.c 두 소스를 컴파일하면 '중복된 정의가 있다'는 의미의 오류 메시지 출력. (이런것이 이름 충돌)
```
gcc list0532A.c list0532B.c -o list0532B
```

- 파일 스코프를 이용한 충돌 회피

위의 list0532A.c 수정 -> list0532A\_2.c (static을 붙여서)
```
$ gcc list0532A_2.c list0532B.c -o list0532B
$ ./list0532B
good morning, sir! (1)
$
```

main() 안에서 func1()을 직접 호출하지 않고, func2()를 거쳐서 호출하면 list0532B.c에 정의된 func1()이 실행됨.

main의 func1();을 func2(); 로 수정
```
$ gcc list0532A_2.c list0532B.c -o list0532B
$ ./list0532B
good morning, sir! (2)
$
```

- 명명 규칙에 의한 이름 공간 설정

파일 스코프를 사용한 로컬 함수의 정의는 객체지향의 private 메소드에 가까운 느낌으로 생각하면 위화감이 적을 것.
실제로 파일 단위로 클래스를 정의하면 C에서도 객체지향 설계에 기반한 프로그래밍을 실현할 수 있음.
하지만 C에서는 이 이상 정밀한 이름 공간 관리를 할 수 없음.

-----

### 옵션 해석

> 프로그램에 전달하는 파라미터

터미널 에뮬레이터나 CUI(character user interface) 터미널상의 셸을 잉요한 대화식 조작에서는 프롬프트에 문자열을 입력해 명시적으로 컴퓨터에 지시를 전달.

- 명령 인수 해석

ARGC 와 ARGV

C에서 main()함수는 두개의 인수를 가진다. 두 개의 인수는 그 프로그램이 실행되었을 때 명령줄 문자열에 관한 정보를 얻는 변수.
main()함수가 받아오는 인수의 이름으로는 관습적으로 argc와 argv가 이용됨. argument count, argument vector를 줄여서 이름 붙인 변수.


list0612A.c 를 실행해보면 명령줄 문자열 획득 가능.

list0612B.c 를 실행.

이 프로그램은 문자열 비교 함수 strcmp()를 사용. 실행한 명령이 foo라면 비교한 결과는 0이 되므로 printf("Hello, Foo!\n"); 가 실행됨. 이외에는 bar!가 실행.

- 파일명에 따른 동작 전환

실행 파일 이름은 foo로 지정해서 컴파일. 또한 그 파일에 다음처럼 심볼릭 링크(symbolic link)로 bar라는 이름도 붙였다. 실행 결과는??
```
$ gcc list0612B.c -o foo
$ ln -s foo bar
$ ./foo
Hello, Foo!
$ ./bar
Hello, Bar!
$
```

> 명령줄 옵션이란

- 처리 대상과 옵션 지정

```
$ gcc list0612A.c -o list0612A
```
여기서 입력한 명령줄 문자열은 'gcc(명령어) list0612A.c(처리 대상) -o(옵션) list0612A(옵션의 인수)'로 해석.

또한 관습적으로 명령줄 옵션에 -으로 시작하는 문자열을 사용.

> 짧은 옵션 해석

프로그램에서는 옵션을 어떻게 해석할까?? 명령줄 옵션을 해석할 때는 getopt()와 getopt\_long()을 사용.
리눅스에는 이들 함수가 표준 C라이브러리에 포함되므로 따로 패키지를 준비할 필요없음.

- 짧은 옵션과 긴 옵션

짧은 옵션 -(하이픈) 에 이어서 영문자 숫자 기호 단일 문자로 나타내는 옵션 형식. 
이들 옵션은 인수가 필요한지에 따라 다시 두 종류로 나뉨.
옵션의 인수는 옵션 문자에 바로 붙여서 지정하거나 공백으로 구별해서 지정.

긴 옵션은 --(하이픈 두 개) 에 이어서 단어로 표현되는 옵션 형식. 
긴 옵션의 인수는 --longopt=argument처럼 =로 연결해 지정하는 것이 관례.


