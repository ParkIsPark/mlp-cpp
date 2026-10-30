# mlp-cpp

MLP 구현 학습을 위한 C++ 개발 환경입니다. 현재 예제는 Eigen 행렬 곱으로 개발 환경의 동작을 확인합니다. 순전파, 역전파, 학습 코드는 다음 단계에서 작성합니다.

## 구성

- C++20
- CMake 3.24 이상
- Visual Studio 2022의 MSVC x64 도구 및 Windows SDK
- Eigen 5.0.1: 행렬·벡터 연산용 헤더 라이브러리
- VS Code의 C/C++ 및 CMake Tools 확장

Eigen은 최초 CMake 구성 시 Git으로 내려받습니다. 고정한 릴리스 태그는 `5.0.1`이며, 세팅 시 확인한 커밋은 `bc3b39870ecb690a623a3f49149a358b95c5781d`입니다. 별도 전역 설치 없이 `build/windows/_deps/eigen3-src`에서 사용합니다. 최초 구성에는 Git과 인터넷 연결이 필요합니다.

## 빌드와 실행

프로젝트 폴더에서 PowerShell로 실행합니다.

```powershell
cmake --preset windows
cmake --build --preset debug
ctest --preset debug
.\build\windows\Debug\eigen_smoke.exe
```

예제의 행렬 곱 결과는 다음과 같습니다.

```text
19 22
43 50
```

최적화 빌드는 다음 명령으로 실행합니다.

```powershell
cmake --build --preset release
ctest --preset release
.\build\windows\Release\eigen_smoke.exe
```

## VS Code

1. 이 저장소 폴더를 VS Code에서 엽니다.
2. 권장 확장인 C/C++과 CMake Tools를 설치합니다.
3. `Ctrl+Shift+B`로 Debug 빌드를 실행합니다.
4. `src/main.cpp`에 중단점을 넣고 `F5`로 디버깅합니다.
5. 작업 실행 메뉴의 `Test (Debug)`로 행렬 연산 검사를 실행할 수 있습니다.

프로젝트 설정에 개인 PC의 절대 경로는 넣지 않습니다. Windows용 프리셋은 Visual Studio 2022 x64를 사용합니다.

## 파일

```text
src/main.cpp          Eigen 행렬 연산 확인 예제
CMakeLists.txt        의존성 및 빌드 대상
CMakePresets.json     Windows Debug/Release 설정
.vscode/              빌드·검사·디버깅 설정
```

Git에는 소스와 설정을 보관합니다. 빌드 결과와 내려받은 Eigen은 `build/` 안에 위치하며 추적하지 않습니다.

## 참고

- [Eigen](https://libeigen.gitlab.io/)
- [Eigen CMake 사용법](https://libeigen.gitlab.io/eigen/docs-master/TopicCMakeGuide.html)
