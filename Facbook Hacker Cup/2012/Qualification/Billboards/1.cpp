#include <cstdio>
#include <string>
using namespace std;

#define min(a,b) (a<b?a:b)
int array[1000];

int fontFits(int font, int width, int height, int stringLengths[], int z){
    int lines = height/font;
    int widthLeft = width;
    int i;

    for (i=0;i<z;i++){
        if (stringLengths[i]*font<=widthLeft){
            widthLeft-=(stringLengths[i]*font+font);
        }
        else if (lines>1){
            lines--;
            widthLeft=width;
            if (stringLengths[i]*font<=widthLeft){
                widthLeft-=(stringLengths[i]*font+font);
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }/* end of for */

    if (i==z)
        return 1;
    else
        return 0;
}

int bSearch(int start, int end, int width, int height, int stringLengths[], int z){
    if (start>end)
        return -1;

    int mid = (start+end)/2;

    if (fontFits(array[mid], width, height, stringLengths, z)){
        if (fontFits(array[mid+1], width, height, stringLengths, z)){
            return bSearch(mid+1,end,width,height,stringLengths,z);
        }
        else{
            return mid;
        }
    }
    else{
        if (fontFits(array[mid-1], width, height, stringLengths, z)){
            return mid-1;
        }
        else{
            return bSearch(start,mid-1,width,height,stringLengths,z);
        }
    }

    return -1;
}

int maxFont(int width, int height, int stringLengths[], int z){
    int fontLimit = min(int(width/stringLengths[0]),height) + 1;
    int i,result;

    if (fontLimit==1){
        if (fontFits(1,width,height,stringLengths,z))
            return 1;
        else
            return 0;
    }

    else{
        for (i=0;i<fontLimit;i++){
            array[i]=i+1;
        }

        result = bSearch(0,fontLimit-1,width,height,stringLengths,z);

        if (result==-1)
            return 0;
        else
            return array[result];
    }
}

int main(){
    int t,i,z;
    int width,height;
    int stringLengths[500];
    char c;

    scanf("%d",&t);

    for (i=0;i<t;i++){
        scanf("%d %d", &width, &height);
        z=0;
        c=getchar();
        while (c==' '){
            stringLengths[z]=0;
            c=getchar();
            while(c!=' '&&c!=10){
                stringLengths[z]++;
                c=getchar();
            }
            z++;
        }
        printf("Case #%d: %d",i+1,maxFont(width,height,stringLengths,z));
        if (i<t-1)
          printf("\n");
    }

    return 0;
}
