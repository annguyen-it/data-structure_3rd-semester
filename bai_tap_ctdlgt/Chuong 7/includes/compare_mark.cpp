#include <bits/stdc++.h>
#include "../class/Candidate.cpp"

#ifndef __compare_mark__cpp
#define __compare_mark__cpp

bool compare_mark(Candidate x, Candidate y){
    return x.getTotalMark() < y.getTotalMark();
}

#endif
