VI Fisher_Yates(int n) {
    VI ret(n);
    iota(allpt(ret), 0);
    repr(i, n - 1) {
        uniform_int_distribution<int> dist(0, i);
        int j = dist(engine);
        swap(ret[i], ret[j]);
    }
    return ret;
}