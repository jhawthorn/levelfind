
levelfind lists directories and files in a level order traversal.

If you have the following directory structure

```
.
├── a
│   ├── 1
│   ├── 2
│   │   ├── i
│   │   └── ii
│   └── 3
├── b
│   ├── 1
│   └── 2
└── c
```

levelfind will output

```
a
b
c
a/1
a/2
a/3
b/1
b/2
a/2/i
a/2/ii
```

## Building

    g++ levelfind.cc -o levelfind

## Installing

    cp levelfind ~/bin/
