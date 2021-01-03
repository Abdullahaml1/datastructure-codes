# DataStructure Codes for this [Course](https://www.youtube.com/playlist?list=PLoK2Lr1miEm-5zCzKE8siQezj9rvQlnca)

| DataStructure Name               | Test Type                                       | Time          | Notes                                                 |
|----------------------------------|-------------------------------------------------|---------------|-------------------------------------------------------|
| STL vector                       | pushing `128000000` (`1GB`) of int64 & clearing | 5.0188 sec    | It uses nearly (`1GB`) of system memory               |
| Bidirectional stack linked based | pushing `128000000` (`1GB`) of int64 & clearing | 8.1857 sec    | the whole struct is `24 byte` the real size > (`3GB`) |
| Bidirectional stack linked based | pushing `500000` of int64                       | nearly .4 sec |                                                       |
| stack array based                | pushing `500000` of int64                       | nearly .4 sec |                                                       |



# Polish Notation Converter and Evaluator
TODO 


# Queue Array based
I will mention a nice sinple trick was used as the base of this code which is ***circular implementation***. We have two pointers front and end pointer. At appending: 
```
end_pointer = (end_pointer +1) % MAX_QUEUE;
```
And at the dequeueing
```
front_pointer = (end_pointer +1) % MAX_QUEUE;
```

Example: if MAX_QUEUE = 10, end_pointer = 4 at the appending end_pointer = (4 +1) % 10 = 5. </br>
But if end_pointer = 9, at the next append end_pointer = (1+9) %10 = 0. **Which means we are circulating around the array with two pointers***. The same happens at the dequeueing process.
