function solution(hp) {
    let total = 0;
    
    while (1) {
        if (hp >= 5) {
            hp -= 5;
        } else if (hp >= 3) {
            hp -= 3;
        } else {
            total += hp;
            break;
        }
        
        total += 1;
    }
    
    return total;
}