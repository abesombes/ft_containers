[37m# test_map[0m
[33m/* ********************************************************************** */
/*                          [37mBASIC TESTS[33m                                   */
/* ********************************************************************** */[0m

printing a map : 
mymap<[35mstring[0m, [35mint[0m> mymap;

mymap.max_size(): 1
printing a map : 

printing a map : 
printing a map : 
ft => 42
[37m# testing upper/lower_bound[0m
printing a map : 
ft => 42
one => 1
printing a map : 
ft => 42
one => 1
              mymap.lower_bound("aaa"): ft:42

printing a map : 
ft => 42
one => 1
printing a map : 
ft => 42
one => 1
              mymap.lower_bound("one"): one:1

printing a map : 
ft => 42
one => 1
printing a map : 
ft => 42
one => 1
              mymap.lower_bound("oae"): one:1

printing a map : 
ft => 42
one => 1
printing a map : 
ft => 42
one => 1
               mymap.lower_bound("ft"): ft:42

printing a map : 
ft => 42
one => 1
printing a map : 
ft => 42
one => 1
   mymap.lower_bound("zzz"): mymap.end()

printing a map : 
ft => 42
one => 1
printing a map : 
ft => 42
one => 1
              mymap.upper_bound("aaa"): ft:42

printing a map : 
ft => 42
one => 1
printing a map : 
ft => 42
one => 1
              mymap.upper_bound("oae"): one:1

printing a map : 
ft => 42
one => 1
   mymap.upper_bound("one"): mymap.end()
printing a map : 
ft => 42
one => 1

printing a map : 
ft => 42
one => 1
               mymap.upper_bound("ft"): one:1

printing a map : 
ft => 42
one => 1
   mymap.upper_bound("zzz"): mymap.end()
printing a map : 
ft => 42
one => 1

printing a map : 
ft => 42
one => 1
printing a map : 
ft => 42
one => 1
printing a map : 
one => 1
[37m# double clear[0m
printing a map : 
one => 1
printing a map : 
printing a map : 
printing a map : 
lol => 0
printing a map : 
lol => 0
xD => 123
printing a map : 
lol => 0
uch => 442
xD => 123
printing a map : 
lol => 0
uch => 442
xD => 123
printing a map : 
lol => 0
uch => 442
xD => 123
printing a map : 
lol => 0
uch => 442
xD => 123
printing a map : 
lol => 8
uch => 442
xD => 123
printing a map : 
lol => 8
uch => 442
xD => 123
printing a map : 
mymap<[35mstring[0m, [35mint[0m> mymap2;
printing a map : 
lol => 8
uch => 442
xD => 123
empty line
printing a map : 
empty line2
empty line3
printing a map : 
empty line4
printing a map : 
lol => 8
uch => 442
xD => 123
empty line5
printing a map : 
lol => 8
uch => 442
xD => 123
printing a map : 
lol => 8
uch => 442
xD => 123
                           map == map2: 1
printing a map : 
lol => 8
uch => 442
xD => 123
printing a map : 
lol => 8
uch => 442
xD => 123

printing a map : 
printing a map : 
lol => 8
uch => 442
xD => 123
printing a map : 
satan => 666
printing a map : 
lol => 8
uch => 442
xD => 123
                         mymap == map2: 0
printing a map : 
satan => 666
printing a map : 
lol => 8
uch => 442
xD => 123

                         mymap <= map2: 0
printing a map : 
satan => 666
printing a map : 
lol => 8
uch => 442
xD => 123

                         mymap >= map2: 1
printing a map : 
satan => 666
printing a map : 
lol => 8
uch => 442
xD => 123

                          mymap > map2: 1
printing a map : 
satan => 666
printing a map : 
lol => 8
uch => 442
xD => 123

                          mymap < map2: 1
printing a map : 
satan => 666
printing a map : 
lol => 8
uch => 442
xD => 123

