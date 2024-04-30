#include <stdio.h>

#include <string.h>

//��ͳ�Ƶ���󵥴ʸ���

#define MAX_WORD_COUNT 500

//�ṹ�壬����ÿ�����ʼ���Ӧ�ĸ���

typedef struct WordCount

{

    char cWord[20];

    int  iCount;

}T_WordCount;



int CalcEachWord(const char* pText);//���㵥�ʸ����������Ϣ��

void LowerText(char* pText);//�ѵ��ʱ��Сд��ʽ

void SwapItem(T_WordCount* ItemA, T_WordCount* ItemB);//��������Ԫ��

void SortWord(T_WordCount* pWordSet);//����



int main(int argc, char* argv[])

{

    char c = 0;
    char pText[10000] = { 0 };
    int i = 0;
    FILE* fp1;
    fp1 = fopen("C://text1.txt", "r");
    while ((c = fgetc(fp1)) != '\n')
    {
        pText[i] = c;
        i++;
    }
    printf("The text is :\n");

    printf("----------------------------------\n");

    printf("%s\n", pText);

    printf("----------------------------------\n");

    printf("The top 5 words is :\n");

    CalcEachWord(pText); return 0;

}



int CalcEachWord(const char* pText)

{

    char cTmp[20] = { 0 };

    int  i = 0;

    char* pTmp = cTmp;

    int  iFlag = 0;



    T_WordCount tWordSet[MAX_WORD_COUNT];

    memset(tWordSet, 0, sizeof(tWordSet));



    while (*pText != '\0')

    {

        if ((*pText >= 'A' && *pText <= 'Z') || (*pText >= 'a' && *pText <= 'z'))

        {



            *pTmp = *pText;

            pTmp++;



        }

        else if (*pText == '-')

        {

            ++pText;

            continue;

        }

        else

        {



            if (strlen(cTmp) > 0)

            {

                LowerText(cTmp);

                iFlag = 0;

                for (i = 0; i < MAX_WORD_COUNT; ++i)

                {

                    if (strlen(tWordSet[i].cWord) > 0)

                    {

                        if (strcmp(tWordSet[i].cWord, cTmp) == 0)

                        {

                            iFlag = 1;

                            tWordSet[i].iCount++;

                            break;

                        }

                    }

                    else

                    {

                        strcpy(tWordSet[i].cWord, cTmp);

                        tWordSet[i].iCount = 1;

                        iFlag = 1;

                        break;

                    }



                }

                if (!iFlag)

                {

                    printf("No more space to save word.\n");

                }



            }

            memset(cTmp, 0, 20);

            pTmp = cTmp;

        }



        ++pText;

    }



    //���� SortWord(tWordSet);

    for (i = 0; i < 5; ++i)

    {

        if (strlen(tWordSet[i].cWord) > 0)

        {

            printf("%s:%d\n", tWordSet[i].cWord, tWordSet[i].iCount);

        }

    }



    return 0;

}



void LowerText(char* pText)

{

    char* pTmp = pText;

    while (*pTmp != '\0')

    {

        if ((*pTmp >= 'A' && *pTmp <= 'Z'))

        {

            *pTmp += 32;

        }



        pTmp++;
    }

}



void SwapItem(T_WordCount* ItemA, T_WordCount* ItemB)

{

    T_WordCount Tmp;

    memset(&Tmp, 0, sizeof(T_WordCount));

    strcpy(Tmp.cWord, ItemA->cWord);
    
    Tmp.iCount = ItemA->iCount;

    strcpy(ItemA->cWord, ItemB->cWord); ItemA->iCount = ItemB->iCount;

    strcpy(ItemB->cWord, Tmp.cWord); ItemB->iCount = Tmp.iCount;

}

//ð�������㷨

void SortWord(T_WordCount* pWordSet) {

    int i, j;

    for (j = 0; j < MAX_WORD_COUNT - 1; j++)

    {

        for (i = 0; i < MAX_WORD_COUNT - 1 - j; i++)

        {

            if (pWordSet[i].iCount < pWordSet[i + 1].iCount)

            {

                SwapItem(&pWordSet[i], &pWordSet[i + 1]);

            }

        }

    }

}