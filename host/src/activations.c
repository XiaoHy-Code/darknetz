#include "activations.h"
#include "main.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_activation_string(ACTIVATION a)
{
    switch(a){
        case LOGISTIC:
            return "logistic";
        case LOGGY:
            return "loggy";
        case RELU:
            return "relu";
        case ELU:
            return "elu";
        case SELU:
            return "selu";
        case RELIE:
            return "relie";
        case RAMP:
            return "ramp";
        case LINEAR:
            return "linear";
        case TANH:
            return "tanh";
        case PLSE:
            return "plse";
        case LEAKY:
            return "leaky";
        case STAIR:
            return "stair";
        case HARDTAN:
            return "hardtan";
        case LHTAN:
            return "lhtan";
        default:
            break;
    }
    return "relu";
}

ACTIVATION get_activation(char *s)
{
    if (strcmp(s, "logistic")==0) return LOGISTIC;
    if (strcmp(s, "loggy")==0) return LOGGY;
    if (strcmp(s, "relu")==0) return RELU;
    if (strcmp(s, "elu")==0) return ELU;
    if (strcmp(s, "selu")==0) return SELU;
    if (strcmp(s, "relie")==0) return RELIE;
    if (strcmp(s, "plse")==0) return PLSE;
    if (strcmp(s, "hardtan")==0) return HARDTAN;
    if (strcmp(s, "lhtan")==0) return LHTAN;
    if (strcmp(s, "linear")==0) return LINEAR;
    if (strcmp(s, "ramp")==0) return RAMP;
    if (strcmp(s, "leaky")==0) return LEAKY;
    if (strcmp(s, "tanh")==0) return TANH;
    if (strcmp(s, "stair")==0) return STAIR;
    fprintf(stderr, "Couldn't find activation function %s, going with ReLU\n", s);
    return RELU;
}

float activate(float x, ACTIVATION a)
{
    switch(a){
        case LINEAR:
            return linear_activate(x);
        case LOGISTIC:
            return logistic_activate(x);
        case LOGGY:
            return loggy_activate(x);
        case RELU:
            return relu_activate(x);
        case ELU:
            return elu_activate(x);
        case SELU:
            return selu_activate(x);
        case RELIE:
            return relie_activate(x);
        case RAMP:
            return ramp_activate(x);
        case LEAKY:
            return leaky_activate(x);
        case TANH:
            return tanh_activate(x);
        case PLSE:
            return plse_activate(x);
        case STAIR:
            return stair_activate(x);
        case HARDTAN:
            return hardtan_activate(x);
        case LHTAN:
            return lhtan_activate(x);
    }
    return 0;
}

// float activate(float x, ACTIVATION a)
// {
//     switch(a){
//         case LINEAR:
//             return activate_CA(x, 0);
//         case LOGISTIC:
//             return activate_CA(x, 1);
//         case LOGGY:
//             return activate_CA(x, 2);
//         case RELU:
//             return activate_CA(x, 3);
//         case ELU:
//             return activate_CA(x, 4);
//         case SELU:
//             return activate_CA(x, 5);
//         case RELIE:
//             return activate_CA(x, 6);
//         case RAMP:
//             return activate_CA(x, 7);
//         case LEAKY:
//             return activate_CA(x, 8);
//         case TANH:
//             return activate_CA(x, 9);
//         case PLSE:
//             return activate_CA(x, 10);
//         case STAIR:
//             return activate_CA(x, 11);
//         case HARDTAN:
//             return activate_CA(x, 12);
//         case LHTAN:
//             return activate_CA(x, 13);
//     }
//     return 0;
// }

void activate_array(float *x, const int n, const ACTIVATION a)
{
    // int i;
    // for(i = 0; i < n; ++i){
    //     x[i] = activate(x[i], a);
    // }
    
    int i = 0;
    switch(a){
        case LINEAR:
            i = 0;
            break;
        case LOGISTIC:
            i = 1;
            break;
        case LOGGY:
            i = 2;
            break;
        case RELU:
            i = 3;
            break;
        case ELU:
            i = 4;
            break;
        case SELU:
            i = 5;
            break;
        case RELIE:
            i = 6;
            break;
        case RAMP:
            i = 7;
            break;
        case LEAKY:
            i = 8;
            break;
        case TANH:
            i = 9;
            break;
        case PLSE:
            i = 10;
            break;
        case STAIR:
            i = 11;
            break;
        case HARDTAN:
            i = 12;
            break;
        case LHTAN:
            i = 13;
            break;
    }
    activate_array_CA(x, n, i);
}

float gradient(float x, ACTIVATION a)
{
    switch(a){
        case LINEAR:
            return linear_gradient(x);
        case LOGISTIC:
            return logistic_gradient(x);
        case LOGGY:
            return loggy_gradient(x);
        case RELU:
            return relu_gradient(x);
        case ELU:
            return elu_gradient(x);
        case SELU:
            return selu_gradient(x);
        case RELIE:
            return relie_gradient(x);
        case RAMP:
            return ramp_gradient(x);
        case LEAKY:
            return leaky_gradient(x);
        case TANH:
            return tanh_gradient(x);
        case PLSE:
            return plse_gradient(x);
        case STAIR:
            return stair_gradient(x);
        case HARDTAN:
            return hardtan_gradient(x);
        case LHTAN:
            return lhtan_gradient(x);
    }
    return 0;
}

void gradient_array(const float *x, const int n, const ACTIVATION a, float *delta)
{
    int i;
    for(i = 0; i < n; ++i){
        delta[i] *= gradient(x[i], a);
    }
} 

