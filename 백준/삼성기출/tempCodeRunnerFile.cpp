    if (dist[nx][ny] == 0)
                    {
                        dist[nx][ny] = dist[xx][yy] + 1;
                        q.push({nx, ny});
                    }
                    else
                    {
                        if (dist[nx][ny] > dist[xx][yy] + 1)
                        {
                            dist[nx][ny] = dist[xx][yy] + 1;
                            q.push({nx, ny});
                        }
                    }