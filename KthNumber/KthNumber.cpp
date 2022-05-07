#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> array;
    vector<vector<int>> commands;

    // Content start

    vector<int> answer;

    int nCommandCount = commands.size();
    cout << "Count : " << nCommandCount << endl;

    int nI = 0;
    int nJ = 0;
    int nK = 0;

    int nSubarraySize = 0;

    int pArrayBuffer[100]{};

    // Process each command
    for (int i = 0; i < nCommandCount; ++i)
    {
        if (commands[i].size() < 3)
        {
            throw 0;
        }

        // Get I, J, K
        nI = commands[i][0];
        nJ = commands[i][1];
        nK = commands[i][2];

        cout << "I : " << nI << endl;
        cout << "J : " << nJ << endl;
        cout << "K : " << nK << endl;

        if (nI > nJ)
        {
            throw 0;
        }

        // Get Subarray Size
        nSubarraySize = nJ - nI + 1;
        cout << "Subarray Size : " << nSubarraySize << endl;

        // Set I, J, K begin from 0
        --nI;
        --nJ;
        --nK;

        // Copy
        for (int j = 0; j < nSubarraySize; ++j)
        {
            pArrayBuffer[j] = array[j + nI];
            cout << pArrayBuffer[j];
        }

        cout << endl;

        if (nSubarraySize > 1)
        {
            for (int j = 0; j < nSubarraySize; ++j)
            {
                for (int k = j + 1; k < nSubarraySize; ++k)
                {
                    if (pArrayBuffer[j] > pArrayBuffer[k])
                    {
                        // Swap
                        int nTemp = pArrayBuffer[j];
                        pArrayBuffer[j] = pArrayBuffer[k];
                        pArrayBuffer[k] = nTemp;
                    }
                }
            }
        }

        for (int j = 0; j < nSubarraySize; ++j)
        {
            cout << pArrayBuffer[j];
        }

        cout << endl;

        answer.push_back(pArrayBuffer[nK]);

        cout << answer[i] << endl;
    }

    cout << "answer size : " << answer.size() << endl;

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i];
    }

    cout << endl;

    return answer;

    // Content end

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
