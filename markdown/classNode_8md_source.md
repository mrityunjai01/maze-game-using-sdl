
# File classNode.md

[**File List**](files.md) **>** [**classNode.md**](classNode_8md.md)

[Go to the documentation of this file.](classNode_8md.md) 


````cpp

# Class Node


[**Class List**](annotated.md) **>** [**Node**](classNode.md)


















## Public Attributes

| Type | Name |
| ---: | :--- |
|  [**Vector2f**](structVector2f.md) | [**pos**](classNode.md#variable-pos)  <br> |


## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Node**](classNode.md#function-node-12) ([**Vector2f**](structVector2f.md) pos) <br>_Construct a new_ [_**Node**_](classNode.md) _::_[_**Node**_](classNode.md) _object._ |
|   | [**Node**](classNode.md#function-node-22) ([**Vector2f**](structVector2f.md) pos) <br> |
|  bool | [**getSelected**](classNode.md#function-getselected) () <br>_Gets the node's selected attribute._  |
|  void | [**setSelected**](classNode.md#function-setselected) (bool sel) <br>_Sets the node's selected attribute._  |








## Public Attributes Documentation


### variable pos 


```cpp
Vector2f Node::pos;
```


## Public Functions Documentation


### function Node [1/2]


```cpp
Node::Node (
    Vector2f pos
) 
```




**Parameters:**


* `pos` 



        

### function Node [2/2]


```cpp
inline Node::Node (
    Vector2f pos
) 
```



### function getSelected 


```cpp
bool Node::getSelected () 
```




**Returns:**

true 




**Returns:**

false 




        

### function setSelected 


```cpp
void Node::setSelected (
    bool sel
) 
```




**Parameters:**


* `sel` 



        

------------------------------
The documentation for this class was generated from the following file `include/node.h`
````

