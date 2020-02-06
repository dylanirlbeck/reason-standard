open AlcoJest;

let suite = suite("List", () => {
  AT.check(AT.list(AT.int), "reverse empty list", List.reverse([]), []);
  AT.check(AT.list(AT.int), "reverse one element", List.reverse([0]), [0]);
  AT.check(
    AT.list(AT.int),
    "reverse two elements",
    List.reverse([0, 1]),
    [1, 0],
  );

  AT.check(
    AT.list(AT.list(AT.int)),
    "sliding - step 1",
    List.sliding([1, 2, 3, 4, 5], ~size=1),
    [[1], [2], [3], [4], [5]],
  );

  AT.check(
    AT.list(AT.list(AT.int)),
    "sliding - step 2",
    [[1, 2], [2, 3], [3, 4], [4, 5]],
    List.sliding([1, 2, 3, 4, 5], ~size=2),
  );

  AT.check(
    AT.list(AT.list(AT.int)),
    "sliding - step 3 ",
    [[1, 2, 3], [2, 3, 4], [3, 4, 5]],
    List.sliding([1, 2, 3, 4, 5], ~size=3),
  );

  AT.check(
    AT.list(AT.list(AT.int)),
    "sliding - step 2, size 2",
    [[1, 2], [3, 4]],
    List.sliding([1, 2, 3, 4, 5], ~size=2, ~step=2),
  );

  AT.check(
    AT.list(AT.list(AT.int)),
    "sliding - step 1, size 3",
    [[1], [4]],
    List.sliding([1, 2, 3, 4, 5], ~size=1, ~step=3),
  );

  AT.check(
    AT.list(AT.list(AT.int)),
    "sliding - step 7",
    [[1, 2], [4, 5]],
    List.sliding([1, 2, 3, 4, 5], ~size=2, ~step=3),
  );

  AT.check(
    AT.list(AT.list(AT.int)),
    "sliding - size 7",
    [],
    List.sliding([1, 2, 3, 4, 5], ~size=7),
  );

  AT.check(
    AT.list(AT.int),
    "map2 empty lists",
    List.map2(~f=(+), [], []),
    [],
  );
  AT.check(
    AT.list(AT.int),
    "map2 one element",
    [2],
    List.map2(~f=(+), [1], [1]),
  );

  AT.check(
    AT.list(AT.int),
    "map2 two elements",
    [2, 4],
    List.map2(~f=(+), [1, 2], [1, 2]),
  );

  AT.check(
    AT.list(AT.int),
    "mapI empty list",
    List.mapI(~f=(i, _) => i, []),
    [],
  );
  AT.check(
    AT.list(AT.int),
    "mapI one element",
    List.mapI(~f=(i, _) => i, ['a']),
    [0],
  );
  AT.check(
    AT.list(AT.int),
    "mapI two elements",
    List.mapI(~f=(i, _) => i, ['a', 'b']),
    [0, 1],
  );

  AT.check(
    AT.list(AT.int),
    "mapI empty list",
    List.mapI(~f=(_, n) => n + 1, []),
    [],
  );
  AT.check(
    AT.list(AT.int),
    "mapI one element",
    List.mapI(~f=(_, n) => n + 1, [(-1)]),
    [0],
  );
  AT.check(
    AT.list(AT.int),
    "mapI two elements",
    List.mapI(~f=(_, n) => n + 1, [(-1), 0]),
    [0, 1],
  );

  AT.check(
    AT.option(AT.int),
    "minimum non-empty list",
    Some(3),
    List.minimum([7, 9, 15, 10, 3, 22], ~compare=Int.compare),
  );
  AT.check(
    AT.option(AT.int),
    "minimum empty list",
    None,
    List.minimum([], ~compare),
  );

  AT.check(
    AT.option(AT.int),
    "maximum non-empty list",
    List.maximum([7, 9, 15, 10, 3, 22], ~compare),
    Some(10),
  );
  AT.check(
    AT.option(AT.int),
    "maximum empty list",
    List.maximum([], ~compare),
    None,
  );

  AT.check(
    AT.option(AT.int),
    "minimum non-empty list",
    Some(3),
    List.minimum([7, 9, 15, 10, 3], ~compare),
  );

  AT.check(
    AT.option(AT.int), 
    "minimum empty list", 
    None,
    List.minimum([], ~compare), 
  );

  AT.check(
    AT.option(AT.int),
    "maximum non-empty list",
    Some(15),
    List.maximum([7, 9, 15, 10, 3], ~compare),
  );
  AT.check(AT.option(AT.int), "maximum empty list", List.maximum([], ~compare), None);

  AT.check(
    AT.pair(AT.list(AT.int), AT.list(AT.int)),
    "partition empty list",
    List.partition(~f=Int.isEven, []),
    ([], []),
  );
  AT.check(
    AT.pair(AT.list(AT.int), AT.list(AT.int)),
    "partition one element",
    List.partition(~f=Int.isEven, [1]),
    ([], [1]),
  );
  AT.check(
    AT.pair(AT.list(AT.int), AT.list(AT.int)),
    "partition four elements",
    List.partition(~f=Int.isEven, [1, 2, 3, 4]),
    ([2, 4], [1, 3]),
  );

  AT.check(
    AT.pair(AT.list(AT.int), AT.list(AT.int)),
    "splitWhen four elements",
    List.splitWhen(~f=Int.isEven, [1, 3, 2, 4]),
    ([1, 3], [2, 4]),
  );
  AT.check(
    AT.pair(AT.list(AT.int), AT.list(AT.int)),
    "splitWhen at zero",
    List.splitWhen(~f=Int.isEven, [2, 4, 6]),
    ([], [2, 4, 6]),
  );
  AT.check(
    AT.pair(AT.list(AT.int), AT.list(AT.int)),
    "splitWhen at end",
    List.splitWhen(~f=Int.isEven, [1, 3, 5]),
    ([1, 3, 5], []),
  );
  AT.check(
    AT.pair(AT.list(AT.int), AT.list(AT.int)),
    "splitWhen empty list",
    List.splitWhen(~f=Int.isEven, []),
    ([], []),
  );

  AT.check(
    AT.list(AT.string),
    "intersperse empty list",
    List.intersperse(~sep="on", []),
    [],
  );
  AT.check(
    AT.list(AT.string),
    "intersperse one turtle",
    List.intersperse(~sep="on", ["turtles"]),
    ["turtles"],
  );
  AT.check(
    AT.list(AT.string),
    "intersperse three turtles",
    List.intersperse(~sep="on", ["turtles", "turtles", "turtles"]),
    ["turtles", "on", "turtles", "on", "turtles"],
  );

  AT.check(
    AT.option(AT.list(AT.char)),
    "init empty list",
    List.initial([]),
    None,
  );
  AT.check(
    AT.option(AT.list(AT.char)),
    "init one element",
    List.initial(['a']),
    Some([]),
  );
  AT.check(
    AT.option(AT.list(AT.char)),
    "init two elements",
    List.initial(['a', 'b']),
    Some(['a']),
  );

  AT.check(
    AT.list(AT.string),
    "append empty lists",
    List.append([], []),
    [],
  );
  AT.check(
    AT.list(AT.string),
    "append empty list",
    List.append([], ["turtles"]),
    ["turtles"],
  );
  AT.check(
    AT.list(AT.string),
    "append empty list",
    List.append(["turtles"], []),
    ["turtles"],
  );
  AT.check(
    AT.list(AT.string),
    "append two lists",
    List.append(["on"], ["turtles"]),
    ["on", "turtles"],
  );

  AT.check(
    AT.list(AT.int),
    "fold empty list",
    List.fold(~f=(list, element) => [element, ...list], ~initial=[], []),
    [],
  );
  AT.check(
    AT.list(AT.int),
    "fold one element",
    [1],
    List.fold(~f=(acc, x) => [x, ...acc], ~initial=[], [1]),
  );
  AT.check(
    AT.list(AT.int),
    "fold three elements",
    List.fold(~f=(acc, x) => [x, ...acc], ~initial=[], [1, 2, 3]),
    [3, 2, 1],
  );
  AT.check(
    AT.list(AT.int),
    "foldRight empty list",
    List.foldRight(~f=(acc, x) => [x, ...acc], ~initial=[], []),
    [],
  );
  AT.check(
    AT.list(AT.int),
    "foldRight one element",
    List.foldRight(~f=(acc, x) => [x, ...acc], ~initial=[], [1]),
    [1],
  );
  AT.check(
    AT.list(AT.int),
    "foldRight three elements",
    List.foldRight(~f=(acc, x) => [x, ...acc], ~initial=[], [1, 2, 3]),
    [1, 2, 3],
  );
  AT.check(
    AT.int,
    "fold issue #18",
    List.fold(~f=(-), ~initial=0, [1, 2, 3]),
    2,
  );
  AT.check(
    AT.int,
    "foldRight issue #18",
    List.foldRight(~f=(-), ~initial=0, [1, 2, 3]),
    2,
  );
  AT.check(
    AT.int,
    "fold issue #18",
    List.fold(~f=(-), ~initial=0, [3, 2, 1]),
    2,
  );
  AT.check(
    AT.int,
    "foldRight issue #18",
    List.foldRight(~f=(-), ~initial=0, [3, 2, 1]),
    2,
  );

  AT.check(
    AT.list(AT.int),
    "insertAt empty list",
    List.insertAt(~index=0, ~value=1, []),
    [1],
  );
  AT.check(
    AT.list(AT.int),
    "insertAt in the middle",
    List.insertAt(~index=1, ~value=2, [1, 3]),
    [1, 2, 3],
  );
  AT.check(
    AT.list(AT.int),
    "insertAt in the front",
    List.insertAt(~index=0, ~value=2, [1, 3]),
    [2, 1, 3],
  );

  /*      the test below would work on Bucklescript, both should show the same behaviour */
  /*  AT.check (AT.list AT.int) "insertAt after end of list" (List.insertAt ~index:4 ~value:2 [1;3]) [2];*/
  AT.check(
    AT.list(AT.int),
    "updateAt index smaller 0",
    List.updateAt(~index=-1, ~f=x => x + 1, [1, 3]),
    [1, 3],
  );
  AT.check(
    AT.list(AT.int),
    "updateAt empty list",
    List.updateAt(~index=0, ~f=x => x + 1, []),
    [],
  );
  AT.check(
    AT.list(AT.int),
    "updateAt empty list",
    List.updateAt(~index=2, ~f=x => x + 1, []),
    [],
  );
  AT.check(
    AT.list(AT.int),
    "updateAt inside the list",
    List.updateAt(~index=1, ~f=x => x + 1, [1, 3]),
    [1, 4],
  );
  AT.check(
    AT.list(AT.int),
    "updateAt in the front",
    List.updateAt(~index=0, ~f=x => x + 1, [1, 3]),
    [2, 3],
  );
  AT.check(
    AT.list(AT.int),
    "updateAt after end of list",
    List.updateAt(~index=4, ~f=x => x + 1, [1, 3]),
    [1, 3],
  );

  AT.check(
    AT.list(AT.int),
    "concatenate two empty lists",
    List.concatenate([[], []]),
    [],
  );
  AT.check(
    AT.list(AT.int),
    "concatenate with one empty list",
    List.concatenate([[1], []]),
    [1],
  );
  AT.check(
    AT.list(AT.int),
    "concatenate with one empty list",
    List.concatenate([[], [1]]),
    [1],
  );
  AT.check(
    AT.list(AT.int),
    "concatenate with several lists",
    List.concatenate([[1], [2], [3]]),
    [1, 2, 3],
  );
  AT.check(
    AT.list(AT.int),
    "concatenate with several lists",
    List.concatenate([[1], [], [2], [], [3]]),
    [1, 2, 3],
  );

  AT.check(
    AT.list(AT.int),
    "initialize length 0",
    List.initialize(0, i => i),
    [],
  );
  AT.check(
    AT.list(AT.int),
    "initialize length 1",
    List.initialize(1, i => i),
    [0],
  );
  AT.check(
    AT.list(AT.int),
    "initialize length 2",
    List.initialize(2, i => i),
    [0, 1],
  );

  AT.check(
    AT.list(AT.int),
    "removeAt index smaller 0",
    List.removeAt(~index=-1, [1, 3]),
    [1, 3],
  );
  AT.check(
    AT.list(AT.int),
    "removeAt empty list",
    List.removeAt(~index=0, []),
    [],
  );
  AT.check(
    AT.list(AT.int),
    "removeAt empty list",
    List.removeAt(~index=2, []),
    [],
  );
  AT.check(
    AT.list(AT.int),
    "removeAt index 1",
    List.removeAt(~index=1, [1, 3]),
    [1],
  );
  AT.check(
    AT.list(AT.int),
    "removeAt index 0",
    List.removeAt(~index=0, [1, 3]),
    [3],
  );
  AT.check(
    AT.list(AT.int),
    "removeAt after end of list",
    List.removeAt(~index=4, [1, 3]),
    [1, 3],
  );

  ();
});