
# Struct PlayerInput


[**Class List**](annotated.md) **>** [**PlayerInput**](structPlayerInput.md)


















## Public Attributes

| Type | Name |
| ---: | :--- |
|  int | [**input\_idx**](structPlayerInput.md#variable-input-idx)  <br> |
|  InputEvent | [**keypressed**](structPlayerInput.md#variable-keypressed)  <br> |
|  int | [**new\_node\_to\_point**](structPlayerInput.md#variable-new-node-to-point)  <br> |
|  int | [**player\_index**](structPlayerInput.md#variable-player-index)  <br> |


## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**PlayerInput**](structPlayerInput.md#function-playerinput-13) () <br> |
|   | [**PlayerInput**](structPlayerInput.md#function-playerinput-23) (InputEvent keyp) <br> |
|   | [**PlayerInput**](structPlayerInput.md#function-playerinput-33) (InputEvent keyp, int new\_node, int input\_idx, int player\_index) <br> |








## Public Attributes Documentation


### variable input\_idx 


```cpp
int PlayerInput::input_idx;
```



### variable keypressed 


```cpp
InputEvent PlayerInput::keypressed;
```



### variable new\_node\_to\_point 


```cpp
int PlayerInput::new_node_to_point;
```



### variable player\_index 


```cpp
int PlayerInput::player_index;
```


## Public Functions Documentation


### function PlayerInput [1/3]


```cpp
inline PlayerInput::PlayerInput () 
```



### function PlayerInput [2/3]


```cpp
inline PlayerInput::PlayerInput (
    InputEvent keyp
) 
```



### function PlayerInput [3/3]


```cpp
inline PlayerInput::PlayerInput (
    InputEvent keyp,
    int new_node,
    int input_idx,
    int player_index
) 
```



------------------------------
The documentation for this class was generated from the following file `include/network_structs.h`