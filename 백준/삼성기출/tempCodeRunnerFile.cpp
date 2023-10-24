ted[arr[nx][ny]] = true;
                sx = nx;
                sy = ny;
                sd = dir[nx][ny];
                DFS(nx, ny, sum + arr[nx][ny]);
                visi