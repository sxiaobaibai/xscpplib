#ifndef XS_MSEQUENCE_H
#define XS_MSEQUENCE_H
#include <iostream>
#include <vector>
#include <queue>

using Mseq = int;

struct MSeq
{
  long long itr_cnt;
  long long dim;
  std::vector<Mseq> M;
  std::vector<Mseq> h;
  MSeq(int dim, std::vector<Mseq> M, std::vector<Mseq> h):itr_cnt(0), dim(dim), M(M), h(h){}
  Mseq next()
  {
    if (itr_cnt < dim)
    {
      return M[itr_cnt++];
    }
    else
    {
      M[dim] = 0;
      for (int i = 0 ; i < dim; ++i)
      {
        M[dim] = (M[dim] + M[i] * h[i]) % 2;
      }
      for (int i = 0; i < dim; ++i)
      {
        M[i] = M[i + 1];
      }
      itr_cnt++;
      return M[dim];
    }
  }
};
#endif
