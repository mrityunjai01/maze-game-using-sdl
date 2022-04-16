
# File classRunner.md

[**File List**](files.md) **>** [**classRunner.md**](classRunner_8md.md)

[Go to the documentation of this file.](classRunner_8md.md) 


````cpp

# Class Runner


[**Class List**](annotated.md) **>** [**Runner**](classRunner.md)








Inherits the following classes: [Entity](classEntity.md)












## Public Attributes

| Type | Name |
| ---: | :--- |
|  int | [**current\_x**](classRunner.md#variable-current-x)  <br> |
|  float | [**dir\_x**](classRunner.md#variable-dir-x)  <br> |
|  float | [**dir\_y**](classRunner.md#variable-dir-y)  <br> |
|  boolean | [**diversity**](classRunner.md#variable-diversity)  <br> |
|  float | [**health**](classRunner.md#variable-health)  <br> |
|  [**Vector2f**](structVector2f.md) | [**pos**](classRunner.md#variable-pos)  <br> |
|  float | [**speed**](classRunner.md#variable-speed)  <br> |
|  float | [**speed\_multiplier**](classRunner.md#variable-speed-multiplier)  <br> |
|  int | [**sprite**](classRunner.md#variable-sprite)  <br> |
|  SDL\_Texture \* | [**text**](classRunner.md#variable-text)  <br> |

## Public Attributes inherited from Entity

See [Entity](classEntity.md)

| Type | Name |
| ---: | :--- |
|  [**Vector2f**](structVector2f.md) | [**pos**](classEntity.md#variable-pos)  <br> |



## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Runner**](classRunner.md#function-runner-15) () <br> |
|   | [**Runner**](classRunner.md#function-runner-25) ([**Vector2f**](structVector2f.md) pos, SDL\_Texture \* p\_tex, float speed) <br>_Construct a new_ [_**Runner**_](classRunner.md) _::_[_**Runner**_](classRunner.md) _object._ |
|   | [**Runner**](classRunner.md#function-runner-15) () <br> |
|   | [**Runner**](classRunner.md#function-runner-45) ([**Vector2f**](structVector2f.md) pos, float speed) <br> |
|   | [**Runner**](classRunner.md#function-runner-55) ([**Vector2f**](structVector2f.md) pos) <br>_Construct a new_ [_**Runner**_](classRunner.md) _::_[_**Runner**_](classRunner.md) _object._ |
|  float | [**get\_speed**](classRunner.md#function-get-speed-12) () <br> |
|  float | [**get\_speed**](classRunner.md#function-get-speed-12) () <br> |
|  void | [**setDir**](classRunner.md#function-setdir-12) (float x, float y) <br> |
|  void | [**setDir**](classRunner.md#function-setdir-12) (float x, float y) <br> |
|  void | [**step**](classRunner.md#function-step-12) () <br> |
|  void | [**step**](classRunner.md#function-step-12) () <br> |

## Public Functions inherited from Entity

See [Entity](classEntity.md)

| Type | Name |
| ---: | :--- |
|   | [**Entity**](classEntity.md#function-entity-12) () <br> |
|   | [**Entity**](classEntity.md#function-entity-22) ([**Vector2f**](structVector2f.md) pos, SDL\_Texture \* p\_tex) <br>_Construct a new_ [_**Entity**_](classEntity.md) _::_[_**Entity**_](classEntity.md) _object._ |
|  SDL\_Rect | [**getCurrentFrame**](classEntity.md#function-getcurrentframe) () <br>_Gets the current rectangular frame of this entity._  |
|  [**Vector2f**](structVector2f.md) & | [**getPos**](classEntity.md#function-getpos) () <br> |
|  SDL\_Texture \* | [**getTexture**](classEntity.md#function-gettexture) () <br>_Gets the texture associated with the_ [_**Entity**_](classEntity.md) _object._ |








## Protected Attributes inherited from Entity

See [Entity](classEntity.md)

| Type | Name |
| ---: | :--- |
|  SDL\_Rect | [**currentFrame**](classEntity.md#variable-currentframe)  <br> |
|  SDL\_Texture \* | [**text**](classEntity.md#variable-text)  <br> |







## Public Attributes Documentation


### variable current\_x 


```cpp
int Runner::current_x;
```



### variable dir\_x 


```cpp
float Runner::dir_x;
```



### variable dir\_y 


```cpp
float Runner::dir_y;
```



### variable diversity 


```cpp
boolean Runner::diversity;
```



### variable health 


```cpp
float Runner::health;
```



### variable pos 


```cpp
Vector2f Runner::pos;
```



### variable speed 


```cpp
float Runner::speed;
```



### variable speed\_multiplier 


```cpp
float Runner::speed_multiplier;
```



### variable sprite 


```cpp
int Runner::sprite;
```



### variable text 


```cpp
SDL_Texture* Runner::text;
```


## Public Functions Documentation


### function Runner [1/5]


```cpp
inline Runner::Runner () 
```



### function Runner [2/5]


```cpp
Runner::Runner (
    Vector2f pos,
    SDL_Texture * p_tex,
    float speed
) 
```




**Parameters:**


* `pos` 
* `p_tex` 
* `speed` 



        

### function Runner [1/5]


```cpp
inline Runner::Runner () 
```



### function Runner [4/5]


```cpp
Runner::Runner (
    Vector2f pos,
    float speed
) 
```



### function Runner [5/5]


```cpp
Runner::Runner (
    Vector2f pos
) 
```




**Parameters:**


* `pos` 
* `p_tex` 
* `speed` 



        

### function get\_speed [1/2]


```cpp
float Runner::get_speed () 
```



### function get\_speed [1/2]


```cpp
float Runner::get_speed () 
```



### function setDir [1/2]


```cpp
void Runner::setDir (
    float x,
    float y
) 
```



### function setDir [1/2]


```cpp
void Runner::setDir (
    float x,
    float y
) 
```



### function step [1/2]


```cpp
void Runner::step () 
```



### function step [1/2]


```cpp
void Runner::step () 
```



------------------------------
The documentation for this class was generated from the following file `include/runner.h`
````

