#include <cstdio>
#include <string>
using namespace std;

int maxFont(int width, int height, int stringLengths[], int z){
    int font = 1;
    int widthLeft,lines,i;

    while(font<=height){
        lines = height/font;
        widthLeft = width;

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
            font++;
        else
            break;
    } /* end of while */

    return font-1;

} /* end of maxFont */

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
