
# File classRenderWindow.md

[**File List**](files.md) **>** [**classRenderWindow.md**](classRenderWindow_8md.md)

[Go to the documentation of this file.](classRenderWindow_8md.md) 


````cpp

# Class RenderWindow


[**Class List**](annotated.md) **>** [**RenderWindow**](classRenderWindow.md)




















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**RenderWindow**](classRenderWindow.md#function-renderwindow-12) () <br> |
|   | [**RenderWindow**](classRenderWindow.md#function-renderwindow-22) (const char \* p\_title, int p\_v, int p\_h) <br>_Construct a new Render Window:: Render Window object._  |
|  void | [**cleanUp**](classRenderWindow.md#function-cleanup) () <br>_Cleans up the window._  |
|  void | [**clear**](classRenderWindow.md#function-clear) () <br>_Clears the window._  |
|  void | [**display**](classRenderWindow.md#function-display) () <br>_Displays the rendered screen._  |
|  int | [**getRefreshRate**](classRenderWindow.md#function-getrefreshrate) () <br>_Gets the refresh rate of the screen._  |
|  SDL\_Texture \* | [**loadTexture**](classRenderWindow.md#function-loadtexture) (const char \* p\_filePath) <br>_Loads a texture to render into the window._  |
|  void | [**render\_dog**](classRenderWindow.md#function-render-dog) ([**Vector2f**](structVector2f.md) v, SDL\_Texture \*& dog) <br>_Renders a dog._  |
|  void | [**render\_edge**](classRenderWindow.md#function-render-edge) (float x1, float y1, float x2, float y2) <br>_Renders an edge._  |
|  void | [**render\_entity**](classRenderWindow.md#function-render-entity) ([**Entity**](classEntity.md) & p\_ent) <br>_Renders an_ [_**Entity**_](classEntity.md) _._ |
|  void | [**render\_healthbar**](classRenderWindow.md#function-render-healthbar) (float h) <br>_Renders the health bar._  |
|  void | [**render\_node**](classRenderWindow.md#function-render-node) ([**Node**](classNode.md) & node, SDL\_Texture \*& blue\_flag, SDL\_Texture \*& yellow\_flag) <br>_Renders a node._  |
|  void | [**render\_prof**](classRenderWindow.md#function-render-prof) ([**Vector2f**](structVector2f.md) v, SDL\_Texture \*& prof) <br>_Renders a prof._  |
|  void | [**render\_runner**](classRenderWindow.md#function-render-runner) ([**Runner**](classRunner.md) & rnr) <br>_Renders a runner._  |
|  void | [**render\_speedbar**](classRenderWindow.md#function-render-speedbar) (float speed) <br>_Renders the speed bar._  |
|  void | [**render\_theme**](classRenderWindow.md#function-render-theme) (int w, int h, SDL\_Texture \*& p\_tex) <br>_Renders the theme._  |
|  void | [**set\_color**](classRenderWindow.md#function-set-color) (int r, int g, int b, int a) <br>_Sets the color of the renderer._  |








## Public Functions Documentation


### function RenderWindow [1/2]


```cpp
inline RenderWindow::RenderWindow () 
```



### function RenderWindow [2/2]


```cpp
RenderWindow::RenderWindow (
    const char * p_title,
    int p_v,
    int p_h
) 
```




**Parameters:**


* `p_title` 
* `p_w` 
* `p_h` 



        

### function cleanUp 


```cpp
void RenderWindow::cleanUp () 
```



### function clear 


```cpp
void RenderWindow::clear () 
```



### function display 


```cpp
void RenderWindow::display () 
```



### function getRefreshRate 


```cpp
int RenderWindow::getRefreshRate () 
```




**Returns:**

int 




        

### function loadTexture 


```cpp
SDL_Texture * RenderWindow::loadTexture (
    const char * p_filePath
) 
```




**Parameters:**


* `p_filePath` 



**Returns:**

SDL\_Texture\* 




        

### function render\_dog 


```cpp
void RenderWindow::render_dog (
    Vector2f v,
    SDL_Texture *& dog
) 
```




**Parameters:**


* `v` 
* `dog` 



        

### function render\_edge 


```cpp
void RenderWindow::render_edge (
    float x1,
    float y1,
    float x2,
    float y2
) 
```




**Parameters:**


* `x1` 
* `y1` 
* `x2` 
* `y2` 



        

### function render\_entity 


```cpp
void RenderWindow::render_entity (
    Entity & p_ent
) 
```




**Parameters:**


* `p_ent` 



        

### function render\_healthbar 


```cpp
void RenderWindow::render_healthbar (
    float h
) 
```




**Parameters:**


* `h` 



        

### function render\_node 


```cpp
void RenderWindow::render_node (
    Node & node,
    SDL_Texture *& blue_flag,
    SDL_Texture *& yellow_flag
) 
```




**Parameters:**


* `node` 
* `blue_flag` 
* `yellow_flag` 



        

### function render\_prof 


```cpp
void RenderWindow::render_prof (
    Vector2f v,
    SDL_Texture *& prof
) 
```




**Parameters:**


* `v` 
* `prof` 



        

### function render\_runner 


```cpp
void RenderWindow::render_runner (
    Runner & rnr
) 
```




**Parameters:**


* `rnr` 



        

### function render\_speedbar 


```cpp
void RenderWindow::render_speedbar (
    float speed
) 
```




**Parameters:**


* `speed` 



        

### function render\_theme 


```cpp
void RenderWindow::render_theme (
    int w,
    int h,
    SDL_Texture *& p_tex
) 
```




**Parameters:**


* `w` 
* `h` 
* `p_tex` 



        

### function set\_color 


```cpp
void RenderWindow::set_color (
    int r,
    int g,
    int b,
    int a
) 
```




**Parameters:**


* `r` 
* `g` 
* `b` 
* `a` 



        

------------------------------
The documentation for this class was generated from the following file `include/render_window.h`
````

