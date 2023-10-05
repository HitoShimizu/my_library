ll baby_step_giant_step(ll a, ll b, ll m) {
    ll rm = (ll)ceil(m);
    ll ax = 1;
    map<ll, ll> dict;
    rep(j, rm) {
        dict[ax] = j + 1;
        ax *= a;
        ax %= m;
    }
    ax = b;
    a = pow_mod(a, m - 2, m);
    a = pow_mod(a, rm, m);
    rep(i, rm) {
        if (dict[ax]) return dict[ax] - 1 + i;
        ax *= a;
        ax %= m;
    }
    return -1;
}