#include "logger.h"


int main(){

    logStartLine("log 1!");
    logInfo("this is info!");
    logWarning("this is warning!");
    logError("this is error!");
    logEndLine();

    logStartLine("log 2!");
    logInfo("this is info!");
    logWarning("this is warning!");
    logError("this is error!");
    logEndLine();


    logStartLine("log 3!");
    logInfo("this is info!");
    logWarning("this is warning!");
    logError("this is error!");
    logEndLine();


}