// 지나가는 길 O, 장애물 X
// park 공원, routes 명령,

function solution(park, routes) {
    let map = park.map(v => v.split(''));
    
    let x = 0, y = 0;
    let w = map[0].length, h = map.length;
    
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (map[i][j] === 'S') {
                x = j, y = i;
            }
        }
    }
    
    routes.forEach(a => {
        let [op, n] = a.split(' ');
        let dx = x, dy = y;
        let flag = 1;
        
        if (op === 'E') {
            for (i = 0; i < Number(n); i++) {
                dx += 1;
                if (dx < 0 || dx >= w || dy < 0 || dy >= h || map[dy][dx] === 'X') {
                    flag = 0;
                    break;
                }
            }
        } else if (op === 'S') {
            for (i = 0; i < Number(n); i++) {
                dy += 1;
                if (dx < 0 || dx >= w || dy < 0 || dy >= h || map[dy][dx] === 'X') {
                    flag = 0;
                    break;
                }
            }
        } else if (op === 'W') {
            for (i = 0; i < Number(n); i++) {
                dx -= 1;
                if (dx < 0 || dx >= w || dy < 0 || dy >= h || map[dy][dx] === 'X') {
                    flag = 0;
                    break;
                }
            }
        } else {
            for (i = 0; i < Number(n); i++) {
                dy -= 1;
                if (dx < 0 || dx >= w || dy < 0 || dy >= h || map[dy][dx] === 'X') {
                    flag = 0;
                    break;
                }
            }
        }
        
        if (flag) x = dx, y = dy;
    })
    
    return [y, x];
}