function gcd(a, b) {
    if (b === 0) return a;
    return gcd(b, a % b);
}

function solution(numer1, denom1, numer2, denom2) {
    const numer = numer1 * denom2 + numer2 * denom1;
    const denom = denom1 * denom2;
    
    const g = gcd(numer, denom);
    
    return [numer / g, denom / g];
}