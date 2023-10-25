#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
}

struct point{
    float x;
    float y;
};

struct vert_AC{
    struct point A;
    struct point C;
};

struct rect{
    struct vert_AC vertices;
    float area;
    float perimeter;
};

double rect_per(struct vert_AC rectangle){
    float a=fabs(rectangle.A.x-rectangle.C.x);
    float b=fabs(rectangle.A.y-rectangle.C.y);
    float per=2*a + 2*b;
    return per;
}

double rect_area(struct vert_AC rectangle){
    float a=fabs(rectangle.A.x-rectangle.C.x);
    float b=fabs(rectangle.A.y-rectangle.C.y);
    float are=a*b;
    return are;
}

void fill_tab(struct rect *rectangle, int n){
    for(int i=0;i<n;i++){
        rectangle[i].area=rect_area(rectangle[i].vertices);
        rectangle[i].perimeter=rect_per(rectangle[i].vertices);
    }
}

void sort(struct rect *rectan, int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(rectan[j].area<rectan[min].area){
                min=j;
            }
            else if(rectan[j].area==rectan[min].area){
                if(rectan[j].perimeter<rectan[j].perimeter){
                    min=j;
                }
            }
        }
        struct rect temp=rectan[i];
        rectan[i]=rectan[min];
        rectan[min]=temp;
    }
}

int compare1(const void *a, const void *b){
    const struct rect *x=(const struct rect *)a;
    const struct rect *y=(const struct rect *)b;
    if(x->perimeter>y->perimeter){
        return 1;
    }
    else if(x->perimeter<y->perimeter){
        return -1;
    }
    else if(x->perimeter == y->perimeter){
        if(x->area>y->area){
            return 1;
        }
        else if(x->area<y->area){
            return -1;
        }
        else if(x->area==y->area){
            return 0;
        }
    }
}

struct vert_AC search(struct rect *r, int n, float obwod, float pole){
    qsort(r,n,sizeof(struct rect), compare1);
    struct rect target;
    target.area=pole;
    target.perimeter=obwod;
    struct rect *szukaj = bsearch(&target, r, n, sizeof(struct rect), compare1);
    struct vert_AC notFound = {{-1,-1}, {-1, -1}};
    if (szukaj == NULL) {
        return notFound;
    }

    return szukaj->vertices;
}

int main(int argc, char *argv[]){
    srand(time(0));
    if(argc<2){
        printf("nie podales argumentu\n");
        return 1;
    }
    int n=atoi(argv[1]);
    struct rect tab_rect[n];
    for(int i=0;i<n;i++){
        tab_rect[i].vertices.A.x=d_rand(1,5);
        tab_rect[i].vertices.A.y=d_rand(1,5);
        tab_rect[i].vertices.C.x=d_rand(1,5);
        tab_rect[i].vertices.C.y=d_rand(1,5);
        printf("A:%f,%f    C:%f,%f\n",tab_rect[i].vertices.A.x,tab_rect[i].vertices.A.y,tab_rect[i].vertices.C.x,tab_rect[i].vertices.C.y);
    }
    printf("\n\n\n");
    fill_tab(tab_rect, n);
    for(int i=0;i<n;i++){
        printf("A:%f,%f    C:%f,%f, pole: %f, obwod: %f\n",tab_rect[i].vertices.A.x,tab_rect[i].vertices.A.y,tab_rect[i].vertices.C.x,tab_rect[i].vertices.C.y, tab_rect[i].area, tab_rect[i].perimeter);
    }
    printf("po posortowaniu: \n\n\n");
    sort(tab_rect,n);
    for(int i=0;i<n;i++){
        printf("A:%f,%f    C:%f,%f, pole: %f, obwod: %f\n",tab_rect[i].vertices.A.x,tab_rect[i].vertices.A.y,tab_rect[i].vertices.C.x,tab_rect[i].vertices.C.y, tab_rect[i].area, tab_rect[i].perimeter);
    }  
    tab_rect[2].area=12.0;
    tab_rect[2].perimeter=25.0;

    struct vert_AC find=search(tab_rect, n, 25.0, 12.0);
    printf("\n\n to powinno byc: A: %f, %f,   C: %f, %f, pole: %f, obwod:%f \n\n",tab_rect[2].vertices.A.x, tab_rect[2].vertices.A.y, tab_rect[2].vertices.C.x, tab_rect[2].vertices.C.y, tab_rect[2].area, tab_rect[2].perimeter);
    printf("a jest: A: %f %f    C: %f %f \n\n", find.A.x, find.A.y, find.C.x, find.C.y);


    return 0;
}