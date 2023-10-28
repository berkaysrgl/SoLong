# SoLong
Bu projede C dilinde yazılan MiniLibx kütüphanesini kullanarak 2D bir oyun yaptım.

<img width="1674" alt="Screen Shot 2023-10-28 at 5 16 33 PM" src="https://github.com/berkaysrgl/SoLong/assets/149242814/240c8d6c-fe1f-48e5-be1b-161173b28332">

IV.3 Map
• The map has to be constructed with 3 components: walls, collectibles, and free
space.

• The map can be composed of only these 5 characters:

0 for an empty space,

1 for a wall,

C for a collectible,

E for a map exit,

P for the player’s starting position.

Here is a simple valid map:

<img width="569" alt="Screen Shot 2023-10-28 at 5 32 41 PM" src="https://github.com/berkaysrgl/SoLong/assets/149242814/f77881de-67e4-4877-96ed-d80935a6f517">

• The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.

If the map contains a duplicates characters (exit/start), you should
display an error message.

• The map must be rectangular.

• The map must be closed/surrounded by walls. If it’s not, the program must return
an error.

• You have to check if there’s a valid path in the map.

• You must be able to parse any kind of map, as long as it respects the above rules.

• Another example of a minimal .ber map:

<img width="601" alt="Screen Shot 2023-10-28 at 5 32 52 PM" src="https://github.com/berkaysrgl/SoLong/assets/149242814/915a9ec5-2c70-44de-91d3-a3a7716da10b">

• If any misconfiguration of any kind is encountered in the file, the program must
exit in a clean way, and return "Error\n" followed by an explicit error message of
your choice.
