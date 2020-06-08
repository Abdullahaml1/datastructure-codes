# DataStructure Codes for this [Course](https://www.youtube.com/playlist?list=PLoK2Lr1miEm-5zCzKE8siQezj9rvQlnca)

| DataStructure Name               | Test Type                                      | Time          | Notes                                                 |
|----------------------------------|------------------------------------------------|---------------|-------------------------------------------------------|
| STL vector                       | pushing `128000000` (`1GB`) of int64 & clearing | 5.0188 sec    | It uses nearly (`1GB`) of system memory               |
| Bidirectional stack linked based | pushing `128000000` (`1GB`) of int64 & clearing | 8.1857 sec    | the whole struct is `24 byte` the real size > (`3GB`) |
| Bidirectional stack linked based | pushing `500000` of int64                      | nearly .4 sec |                                                       |
| stack array based                | pushing `500000` of int64                      | nearly .4 sec |                                                       |
