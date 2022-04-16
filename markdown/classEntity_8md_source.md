
# File classEntity.md

[**File List**](files.md) **>** [**classEntity.md**](classEntity_8md.md)

[Go to the documentation of this file.](classEntity_8md.md) 


````cpp

# Class Entity


[**Class List**](annotated.md) **>** [**Entity**](classEntity.md)










Inherited by the following classes: [Runner](classRunner.md)








## Public Attributes

| Type | Name |
| ---: | :--- |
|  [**Vector2f**](structVector2f.md) | [**pos**](classEntity.md#variable-pos)  <br> |


## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Entity**](classEntity.md#function-entity-12) () <br> |
|   | [**Entity**](classEntity.md#function-entity-22) ([**Vector2f**](structVector2f.md) pos, SDL\_Texture \* p\_tex) <br>_Construct a new_ [_**Entity**_](classEntity.md) _::_[_**Entity**_](classEntity.md) _object._ |
|  SDL\_Rect | [**getCurrentFrame**](classEntity.md#function-getcurrentframe) () <br>_Gets the current rectangular frame of this entity._  |
|  [**Vector2f**](structVector2f.md) & | [**getPos**](classEntity.md#function-getpos) () <br> |
|  SDL\_Texture \* | [**getTexture**](classEntity.md#function-gettexture) () <br>_Gets the texture associated with the_ [_**Entity**_](classEntity.md) _object._ |




## Protected Attributes

| Type | Name |
| ---: | :--- |
|  SDL\_Rect | [**currentFrame**](classEntity.md#variable-currentframe)  <br> |
|  SDL\_Texture \* | [**text**](classEntity.md#variable-text)  <br> |




## Public Attributes Documentation


### variable pos 


```cpp
Vector2f Entity::pos;
```


## Public Functions Documentation


### function Entity [1/2]


```cpp
inline Entity::Entity () 
```



### function Entity [2/2]


```cpp
Entity::Entity (
    Vector2f pos,
    SDL_Texture * p_tex
) 
```




**Parameters:**


* `pos` 
* `p_tex` 



        

### function getCurrentFrame 


```cpp
SDL_Rect Entity::getCurrentFrame () 
```




**Returns:**

SDL\_Rect 




        

### function getPos 


```cpp
inline Vector2f & Entity::getPos () 
```



### function getTexture 


```cpp
SDL_Texture * Entity::getTexture () 
```




**Returns:**

SDL\_Texture\* 




        
## Protected Attributes Documentation


### variable currentFrame 


```cpp
SDL_Rect Entity::currentFrame;
```



### variable text 


```cpp
SDL_Texture* Entity::text;
```



------------------------------
The documentation for this class was generated from the following file `include/entity.h`
````

