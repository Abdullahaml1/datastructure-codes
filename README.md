# DataStructure Codes for this [Course](https://www.youtube.com/playlist?list=PLoK2Lr1miEm-5zCzKE8siQezj9rvQlnca)

| DataStructure Name  | Test Type                            | Time          | Notes                                                  |
|---------------------|--------------------------------------|---------------|--------------------------------------------------------|
| stack linked based  | pushing `128000000` (`1GB`) of int64 | 5.584 sec     | the whole struct is `24 byte` the real size is (`3GB`) |
| STL vector          | pushing `128000000` (`1GB`) of int64 | 3.355 sec     | It uses nearly (`1GB`) of system memory                |
| stack  linked based | pushing `500000` of int64            | nearly .4 sec |                                                        |
| stack array based   | pushing `500000` of int64            | nearly .4 sec |                                                        |
