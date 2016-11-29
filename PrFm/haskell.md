# Haskell

## Haskell overview

In contrast to math, function application in Haskell is is denoted using space.

Custom functions are defined within a _script_ - a simple text file with the `.hs` extension.


Haskell comes with many function in the standard library (*standard prelude*) - many that we already know from prolog.

* `head [1, 2, 3, 4, 5]` - `1`
* `head [1, 2, 3, 4, 5]` - `[2, 3, 4, 5]`
* `take 3 [1, 2, 3, 4, 5]` - `[1, 2, 3]`
* `drop 3 [1, 2, 3, 4, 5]` - `[4, 5]`
* `lenght [1, 2, 3, 4, 5]` - `5`
* `sum [1, 2, 3, 4, 5]` - `15`
* `product [1, 2, 3, 4, 5]` - `120`
* `reverse [1, 2, 3, 4, 5]` - `[5, 4, 3, 2, 1]`
* Append two lists `[1, 2, 3] ++ [4, 5]`
* Select the nth element of a list `[1, 2, 3, 4, 5] !! 2` - `3`

!!! warning

    * function application is denoted using space
    * function appliaction binds stronger than all other operators
    `f a b + c * d` ➪ `f(a b) + c d`
    `f a + b` ➪ `(f a) + b`


Any functions with two arguments can be written bewtwen its arguments by enclosuing the name of the function in singl eback quotes. This can improve readability

```haskell
average ns = sum ns `div` lenght ns
-- equivalent to
average ns = div (sum ns) (lenght ns)

```

## Naming conventions

* functions and arguments must be lowercase
* list arguments have an s suffix (by convention)
    * nss would be a list of lists

## GHCi
GHC = Glasgow Haskell compiler.

```bash
$ ghci
$ ghci my_script.hs
```

```haskell
-- Load a file
:l "demo.hs"
:load "demo.hs"

-- reload the last loaded file (here: demo.hs)
:reload
:r

-- set and open editor
: set editor name
: edit filename.hs
: edit

-- show type of expr
: type expr

-- other
: ?
: quit
```

## Data Structure



List can be defined as $$Lst := Nil\; |\; const\; e \;Lst$$, where $$e$$ is the head and the second $$Lst$$ the tail.


Definition of an abstract data type


```haskell
data lst a = Nil |  Cons a (Lst a)
    derivating (Show)

l1 = Cons 'a' (Cons 'b' Nil)
len Nil = 0
len (Cons x xs) = 1 + (len xs)
```


However, lists can be used much simpler using eg. `[1..10]`

!!! note

    Haskell is strongly typed! (uses prolog-style proof to get the type) - use `:type "abc"` to get the type of sth.


## Demos

!!! seealso

    Code Samples in the `demo` directory.

### Demo Factorial

\[
 n!={\begin{cases}1&{\text{if }}n=0,\\(n-1)!\times n&{\text{if }}n>0\end{cases}}.
\]

Imperative version (pseudo code)

```
n = input
result = 1;
```c++
while(n > 0){
    result = result*n;
    n = n-1;
}
```

Functional version (recursive definition)

```haskell
fact 0 = 1;
fact n = n * (fact n - 1);
```

Functional is much more readable, since it is basically equivalent to the mathematical definition.

Because there are no side effects, the functional version can be optimized and parallelized by the compiler. This can be seen, when the above program is executed for a huge number.


### Demo Fibonacci

Definition

\[
F_{1}=1,\\
F_{2}=1,\\
F_{n}=F_{n-1}+F_{n-2}
\]


functional version (again, based on recursion)

```haskell
fib 0 = 1
fib 1 = 1
fib (n) = (fib (n-1)) + (fib (n-2))
```

Example usage

```haskell
-- first 12 elements of the fibonacci series
fibsN n = map fib [0..n]
fibsN 12
-- Output: [1,1,2,3,5,8,13,21,34,55,89,144,233]

{- or get ALL the fibonacci numbres using an
infinite implementation -}
fibs = map fib [0..]
-- Output: [1,1,2,3,5,8,13,21,34,55,89,144,233, ...

-- thanks to lazy loading & take function, take the first n with fibs
take 12 fibs
-- Output: [1,1,2,3,5,8,13,21,34,55,89,144,233]
```

The compiler can use tail recursion or use dynamic programming for optimizing.

## Types

type
: Collection of related values

Basic Types

* `Bool` - contains `True` and `False`
* `Char` - `a`, `b`, ...
* `String` (which is actually a list of char `:type "foo"` ➪ `"foo" :: [Char]`)
* `Int` - fixed size
* `Integer` - No fixed size
* `Float`
* `Double`

Types can be set manually using two colons: `1 :: Float`

Haskell (automatically) determines the Types at compile time using **Type inference** - which makes Haskell type safe (no type errors at runtime). This means, that a function must allways return values of the same type (eg. not 1 and False)

Examples

* `Bool` contains `True` and `False`
* `Bool -> Bool` Contains all Functions, that map Bool-Arguments to a resulting Bool (eg. `not`)

### Lists

Sequence of elements **of the same type**. The type only defines the type and nothing else (eg. lenght). Lists don't have to be finite.

Examples

* `[False, True, False] :: [Bool]`
* `['a', 'n', 'q'] :: [Char]`
* `["Foo", "Baa"] :: [[Char]]` (or `:: [String]`)

### Tuples

Tuples are a **finite** sequence of components of **possibly different types**. The type conveys (in contrast to List) the arity of the tuple.

Tupels of size 1 are not permitted - But 0, 2, 3 ... n.

Examples

* `(False, True) :: (Bool, Bool)`
* `('a', True, "Haha") :: (Char, Bool, [Char])`

### Function types
A function is a **mapping** from agruments of some type to results of possibly another type.

Examples

* `even :: Int -> Bool`
* `add :: (Int, Int) -> Int`

Note, that the `:type` command in GHCi will return the Curryed version of it - eg: `:type (+)` ➪ `(+) :: Num a => a -> a -> a` Which means that it takes two arguments (one at a time) of type `a` and returns a result of type `a` as well.

Currying enables _partially applying a curried function_, for example `double = (* 2)`, `double 15`.

```haskell
add x y =x + y
-- means
add = \ x -> (\ y -> x + y)
```

!!! note

    To avoid excess of parentheses when using curried functions, the following conventions are adopted:

    * Arrows `->` are **right associative** (eg. `int->int->int->int` = `int->(int->(int->int))`)
    * Function applications are **left associative** (eg. `add x y z` = `((add x)y)z`)


### Polymorphic Functions

Polymorphic Functions are Type Variables where the type is substituted wit a a placeholder. These type parameters must be lowercase and are usually a single character. Example `length :: [a] -> Int` or `zip :: [a] => [b] -> [(a,b)]`

### Overloaded Functions

The `+` Method should be applicable for `Int`s as well as `Float`s etc. This can be achived using *type classes*. Type classes are similar to interfaces.

To enable overloaded functions, polymorphic functions can be applyed with **class constraints**.

`(+) Num a => a -> a -> a`

Common type classes are `Num` (numeric types), `Eq` (equality types, eg `==`), `Ord` (ordered types, eg. `>` or `<`)

!!! todo

    Duck typing theorie lesen (Bevavuiral Polimorphism)
    Type hints

## Defining Functions

* Use other Functions - eg. ```even n = n `mod` 2 == 0```
* Conditional Expressions - Like "Java"
    * Exactly: ONE if and ONE else
    * May be nested

    ```haskell
    signum n = if n < 0 then -1 else
                    if n == 0 then 0
                    else 1
    ```

* Guarded Equations
    * Mathematical intuition
    * `otherwise` is synonym for `True`
    * The Order, in which the Guards are defined is crucally important!
    * The symbol `|` is read as _"such that"_
    * other is not required but pretty and readable

    ```haskell
    signum n | n < 0     = -1
             | n == 0    = 0
             | otheriwse = 1
    ```

* Pattern Matching
    * eg. not - well readable (if possible)
    * order should NOT matter
    * Can only bind a variable ONCE! (eg. `b&& b=b` is invalid)

    ```haskell
    True && True = True
    True && False = False
    False && True = False
    False && False = False
    -- simpler with wildcard patterns
    True && True = True
    _ && _ = False
    ```

* List Patterns
    * Internally, every non-empty list is constructed by repeated use of the `cons` operator
    * `x : xs` matches only non-empty lists!

    ```haskell
    -- Partical use of cons
    head (x : _) = x
    tail (_ : xs) = xs --

    -- Syntactic Shugar
    [1,2,3,4]
    -- is equal to
    1 : (2 : (3 : (4 : []))).
    ```

* Lambda Expressions
    * void naming functions that are only referenced once
    * return functions as results

    ```haskell
    > (\x -> x + x) 2
    4
    ```

* Operator Sections
    * Convert infix operator into curried function

    ```haskell
    plusone = (1+)
    divideByTwo = (/2)
    plusone 2
    ```

## List Comprehension

Set Comprehensions are common in mathematics. Haskell knows a similar notation. It's the same concept as in Python but with different syntax.

List Comprehensions are a very elegant way to perform iteration in the declarative style.

```haskell
-- math: {x^2 | x \in {1...5}}
[x^2 | x <- [1..5]]
-- Result: [1,4,9,16,25]

[(x, y) | x <- [1,2,3], y <- [4, 5]]
-- Result: [(1,4),(1,5),(2,4),(2,5),(3,4),(3,5)]
[(x, y) | y <- [4, 5], x <- [1,2,3]]
-- Result: [(1,4),(2,4),(3,4),(1,5),(2,5),(3,5)]
[(x,y) |  x <- [1..3], y <- [x..3]]
-- Result: [(1,1),(1,2),(1,3),(2,2),(2,3),(3,3)]
concat xss = [x | xs <- xss, x <- xs]

-- using guards
factors n = [x | x <- [1..n], n `mod` x == 0]
-- prime n = factors n == [1, n]
-- prime 15

```

* `x <- [1..5]` is a **Generator**.
* Comprehensions can have multiple generators, separated by commas.
    * The **order** is important (like nested loops)
    * generators can depend on the variables that are introduced by earlier generators
* guards restrict the values (equivalent to `if` in python list comprehensions)

#### The zip function

Zip generates a list of pairs for two given lists.

```haskell
zip [1,2,3] ['a', 'b', 'c']
-- Result: zip [1,2,3] ['a', 'b', 'c']
positions x xs = [i | (k, i) <- zip xs [0 ..], k == x]
```

!!! note

    Strings are nothing else than a list of Chars. Therefore, operations such as `zip`, `take` or `lenght` work on strings as well.

    ➪ "String comprehensions"