/* 
 *    a / b = x (mod INF)
 *    b ^ (INF - 1) = 1 (mod INF)
 * => a / b = a * b ^ (INF - 2)  (mod INF)
 */

// (a ^ e) mod inf
LL fast_exp(LL a, LL e, LL inf) {
  LL ret = 1;
  while (e) {
    if (e & 1) {
      ret = ((ret % inf) * a) % inf;
      --e;
    } else {
      a = ((a % inf) * (a % inf)) % inf;
      e >>= 1;
    }
  }
  return ret;
}

