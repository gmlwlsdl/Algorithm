function solution(board) {
    // 상 하 좌 우 상좌 상우 하좌 하우
    const dx = [0, 0, -1, 1, -1, 1, -1, 1];
    const dy = [1, -1, 0, 0, 1, 1, -1, -1];
    
    const n = board.length;
    let ans = n * n;
    
    let arr = [];
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] === 1) {
                arr.push([j, i]); // x, y
                ans--;
            }
        }
    }
    
    if (ans === 0) return 0;
    
    arr.forEach(a => {
        for (j = 0; j < 8; j++) {
            const x = a[0] + dx[j];
            const y = a[1] + dy[j];
            
            if (x >= 0 && x < n && y >= 0 && y < n && board[y][x] === 0) {
                board[y][x] = 1;
                ans--;
            }
        }
    })
    
    return ans;
}