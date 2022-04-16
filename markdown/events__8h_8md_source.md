
# File events\_8h.md

[**File List**](files.md) **>** [**events\_8h.md**](events__8h_8md.md)

[Go to the documentation of this file.](events__8h_8md.md) 


````cpp

# File events.h


[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**events.h**](events_8h.md)

[Go to the source code of this file.](events_8h_source.md)



* `#include <SDL2/SDL.h>`
* `#include <enet/enet.h>`
* `#include "utils.h"`
* `#include <SDL2/SDL_image.h>`
* `#include <SDL2/SDL_mixer.h>`
* `#include "send_input.h"`
* `#include "screens.h"`
* `#include "assets.h"`
* `#include "game_objects.h"`
* `#include "map_data_extern.h"`
* `#include "constants.h"`













## Public Attributes

| Type | Name |
| ---: | :--- |
|  ENetHost \* | [**client\_host**](events_8h.md#variable-client-host)  <br>_The client connection._  |
|  ENetPeer \* | [**peer**](events_8h.md#variable-peer)  <br>_The Server connection._  |


## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**handle\_event**](events_8h.md#function-handle-event) (SDL\_Event e, int & prev\_node\_selected) <br>_Handles an event on client side._  |








## Public Attributes Documentation


### variable client\_host 


```cpp
ENetHost* client_host;
```



### variable peer 


```cpp
ENetPeer* peer;
```


## Public Functions Documentation


### function handle\_event 


```cpp
void handle_event (
    SDL_Event e,
    int & prev_node_selected
) 
```




**Parameters:**


* `e` 
* `prev_node_selected` 



        

------------------------------
The documentation for this class was generated from the following file `include/events.h`
````

