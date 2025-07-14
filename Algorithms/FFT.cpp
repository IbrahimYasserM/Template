typedef std::complex<long double> cd;
const long double PI = acos(-1);

void fft(std::vector<cd> &a, bool invert){
    int n = a.size();

    for(int i=1, j=0; i<n; ++i){
        int bit = n>>1;
        for(; j&bit; bit>>=1)
            j ^= bit;
        j ^= bit;

        if(i < j)
            std::swap(a[i], a[j]);
    }
    for(int len = 2; len <=n; len<<=1){
        long double ang = 2 * PI / len * (invert?-1:1);
        cd wlen(std::cos(ang), std::sin(ang));
        for(int i=0; i<n; i+=len){
            cd w(1);
            for(int j=0; j<len/2; j++){
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if(invert)
        for(cd &x : a)
            x /= n;
}

std::vector<long long> multiply(std::vector<int> const &a, std::vector<int> const&b){
    std::vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n<a.size()+b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for(int i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);

    std::vector<long long> res(n);
    for(int i=0; i<n; ++i)
        res[i] = std::round(fa[i].real());
    return res;
}
