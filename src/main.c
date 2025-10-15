#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_int(const char* str){
    char* equal_index = strchr(str, '=');
    if(equal_index == NULL){
        printf("Equality sign not found.\n");
        return -1;
    }
    return atoi(equal_index + 1);
}

int main(int argc, char* argv[]){
    char* flag1;
    char* flag2;
    int lower_bound = 0, upper_bound = 0;
    int lower_found = 0, upper_found = 0;

    if(argc == 1) {
        fprintf(stderr, "No flags found.\n");
        return 1;
    }

    if(argc == 2){
        flag1 = argv[1];
        if(strstr(flag1, "lower_bound") != NULL){
            fprintf(stderr, "Flag --upper_bound is missing.\n");
            return 1;
        }

        else if(strstr(flag1, "upper_bound") != NULL){
            fprintf(stderr, "Flag --lower_bound is missing.\n");
            return 1;
        }

        else {
            fprintf(stderr, "Invalid flag: %s\n", flag1);
            return 1;
        }
    }

    if(argc == 3){
        flag1 = argv[1];
        flag2 = argv[2];

        if(strstr(flag1, "lower_bound") != NULL){
            lower_found = 1;
        }
        if(strstr(flag2, "lower_bound") != NULL){
            lower_found = 1;
        }
        if(strstr(flag1, "upper_bound") != NULL){
            upper_found = 1;
        }
        if(strstr(flag2, "upper_bound") != NULL){
            upper_found = 1;
        }

        if(!lower_found && !upper_found){
            fprintf(stderr, "No flags found.\n");
            return 1;
        }

        if(!lower_found){
            fprintf(stderr, "Flag --lower_bound is missing.\n");
            return 1;
        }
        if(!upper_found){
            fprintf(stderr, "Flag --upper_bound is missing.\n");
            return 1;
        }

        if(strstr(flag1, "lower_bound") != NULL){
            lower_bound = parse_int(flag1);
            upper_bound = parse_int(flag2);
        }
        else{
            lower_bound = parse_int(flag2);
            upper_bound = parse_int(flag1);
        }
    }

    if(lower_bound > upper_bound){
        fprintf(stderr, "The lower bound is greater than the upper bound.\n");
        return 1;
    }

    for(int i = lower_bound; i < upper_bound+1; i++){
        printf("%d", i);
        if(i < upper_bound){
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
