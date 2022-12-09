from ib111 import week_10  # noqa
from typing import List, Tuple, Dict, Optional

# «Numberlink¹» je logický hlavolam, v němž je zadána čtvercová síť s několika
# dvojicemi čísel a cílem je spojit všechny dvojice stejných čísel lomenou
# čarou, přičemž každým políčkem čtvercové sítě musí procházet právě jedna
# čára. V naší implementaci místo kreslení čar do čtvercové sítě vepíšeme
# čísla všude tam, kudy by spojnice zadaných čísel prošla.
#
# ¹ ‹https://en.wikipedia.org/wiki/Numberlink›
#
# Příklad vstupu:
#
#  ┌───┬───┬───┬───┬───┬───┬───┐
#  │   │   │   │ 4 │   │   │   │
#  ├───┼───┼───┼───┼───┼───┼───┤
#  │   │ 3 │   │   │ 2 │ 5 │   │
#  ├───┼───┼───┼───┼───┼───┼───┤
#  │   │   │   │ 3 │ 1 │   │   │
#  ├───┼───┼───┼───┼───┼───┼───┤
#  │   │   │   │ 5 │   │   │   │
#  ├───┼───┼───┼───┼───┼───┼───┤
#  │   │   │   │   │   │   │   │
#  ├───┼───┼───┼───┼───┼───┼───┤
#  │   │   │ 1 │   │   │   │   │
#  ├───┼───┼───┼───┼───┼───┼───┤
#  │ 2 │   │   │   │ 4 │   │   │
#  └───┴───┴───┴───┴───┴───┴───┘
#
# a řešení:
#
#  ┌───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┬───┐
#  │ 2 │ 2 │ 2 │ 4 │ 4 │ 4 │ 4 │ │▒▒▒│▒▒▒│▒▒▒│ 4 │ ◦ │ ◦ │ ◦ │
#  ├───┼───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┼───┤
#  │ 2 │ 3 │ 2 │ 2 │ 2 │ 5 │ 4 │ │▒▒▒│ 3 │▒▒▒│▒▒▒│▒2▒│░5░│ ◦ │
#  ├───┼───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┼───┤
#  │ 2 │ 3 │ 3 │ 3 │ 1 │ 5 │ 4 │ │▒▒▒│ ◦ │ ◦ │ 3 │ 1 │░░░│ ◦ │
#  ├───┼───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┼───┤
#  │ 2 │ 5 │ 5 │ 5 │ 1 │ 5 │ 4 │ │▒▒▒│░░░│░░░│░5░│ ◦ │░░░│ ◦ │
#  ├───┼───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┼───┤
#  │ 2 │ 5 │ 1 │ 1 │ 1 │ 5 │ 4 │ │▒▒▒│░░░│ ◦ │ ◦ │ ◦ │░░░│ ◦ │
#  ├───┼───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┼───┤
#  │ 2 │ 5 │ 1 │ 5 │ 5 │ 5 │ 4 │ │▒▒▒│░░░│ 1 │░░░│░░░│░░░│ ◦ │
#  ├───┼───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┼───┤
#  │ 2 │ 5 │ 5 │ 5 │ 4 │ 4 │ 4 │ │▒2▒│░░░│░░░│░░░│ 4 │ ◦ │ ◦ │
#  └───┴───┴───┴───┴───┴───┴───┘ └───┴───┴───┴───┴───┴───┴───┘
#
# (Srovnejte s obrázkem na Wikipedii.)
#
# Máme připravené typové aliasy ‹Grid› pro 2D seznamy, ‹Position› pro dvojice
# souřadnic (sloupec, řádek; číslujeme jako obvykle od nuly zleva a shora)
# a ‹Ends›, jehož význam je vysvětlen níže.

Grid = List[List[int]]
Position = Tuple[int, int]
PositionKey = Tuple[int, bool]
Ends = Dict[PositionKey, Position]


# Nejprve implementujte čistou funkci ‹get_ends›, která dostane na vstup zadání
# hlavolamu jako 2D seznam, který obsahuje pouze nezáporná celá čísla, přičemž
# nuly reprezentují prázdná políčka a ostatní čísla ve vstupu jsou vždy přesně
# dvakrát. Funkce vrátí slovník typu ‹Ends›, v němž jsou pro každé kladné číslo
# ‹n› ze vstupu dvě položky:
# ‹(n, True): (x_1, y_1)› a ‹(n, False): (x_2, y_2)›,
# kde ‹(x_1, y_1)› a ‹(x_2, y_2)› jsou souřadnice výskytu daného čísla.
# Na tom, které souřadnice jsou u položky s ‹True› a s ‹False›, nezáleží.
# ‹True›, ‹False› zde používáme jenom proto, abychom mohli mít dvě různé
# položky pro každé číslo.
# (Proč volíme zrovna takovou reprezentaci, je vysvětleno níže.)

def get_ends(grid: Grid) -> Ends:
    dictionary = {}
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] != 0:
                if dictionary.get((grid[i][j], True)) is None:
                    dictionary[(grid[i][j], True)] = (j, i)
                else:
                    dictionary[(grid[i][j], False)] = (j, i)
    return dictionary


# Dále implementujte čistou funkci ‹solve›, která najde řešení pro zadaný
# vstup. Pokud žádné řešení neexistuje, vrátí ‹None›. Pokud existuje více než
# jedno řešení, vrátí libovolné z nich.
#
# «Nápověda:» Využijte backtracking. Spočítejte si nejdříve pozice čísel pomocí
# funkce ‹get_ends›. Na tyto pozice se můžete dívat jako na dva konce provázku,
# které se snažíte dostat k sobě a spojit. V každém kroku backtrackingu si
# zvolte jeden z „konců“ a pokuste se jej posunout – možné směry posunutí jsou
# právě ty lokální volby, které při backtrackingu provedete. Přitom je vhodné
# volit z možných konců takový, který má co nejméně těchto možných směrů.
# Kromě posouvání konců si zároveň chcete zaznamenat, která políčka už jsou
# obsazena.

RULEST = Dict[str, int]


def get_move_rules() -> RULEST:
    return {
        "RIGHT": 1,
        "LEFT": -1,
        "UP": -1,
        "DOWN": 1,
    }


def get_move_in_rules(dir: str, rules: RULEST) -> int:
    return rules[dir]


def get_all_move_in_rules():
    MOVE_RULES = get_move_rules()
    RIGHT = get_move_in_rules("RIGHT", MOVE_RULES)
    LEFT = get_move_in_rules("LEFT", MOVE_RULES)
    UP = get_move_in_rules("UP", MOVE_RULES)
    DOWN = get_move_in_rules("DOWN", MOVE_RULES)
    return (RIGHT, LEFT, UP, DOWN)


def get_coords_val(x: int, y: int, grid: Grid) -> int:
    if x < 0 or y < 0 or y >= len(grid) or len(grid[y]) <= x:
        return -1
    return grid[y][x]


def get_all_move_rules_possibilites():
    RIGHT, LEFT, UP, DOWN = get_all_move_in_rules()
    return {
        "0": (RIGHT, LEFT, UP, DOWN),
        "1": (LEFT, UP, DOWN, RIGHT),
        "2": (UP, DOWN, RIGHT, LEFT),
        "3": (DOWN, RIGHT, LEFT, UP),
    }

def get_all_coords(x, y, grid):
    RIGHT, LEFT, UP, DOWN = get_all_move_in_rules()
    coordsVal = get_coords_val(x, y, grid)
    coordsValRight = get_coords_val(x + RIGHT, y, grid)
    coordsValLeft = get_coords_val(x + LEFT, y, grid)
    coordsValUp = get_coords_val(x, y + UP, grid)
    coordsValBottom = get_coords_val(x, y + DOWN, grid)
    return (coordsVal, coordsValRight, coordsValLeft, coordsValUp, coordsValBottom)

def get_move_possibilities(coordsKey: PositionKey, coords: Position, gridEnds: Ends, grid: Grid, has_exclusion: bool) -> Dict:
    x, y = coords
    num_possibilities = 0
    hasEndNeighbor = False
    moves_dict = {}
    RIGHT, LEFT, UP, DOWN = get_all_move_in_rules()
    coordsVal, coordsValRight, coordsValLeft, coordsValUp, coordsValBottom = get_all_coords(x, y, grid)
    coordsValList = [
    {
        "type_": "RIGHT",
        "move_rule": RIGHT,
        "val": coordsValRight
    },
    {
        "type_": "LEFT",
        "move_rule": LEFT,
        "val":  coordsValLeft
    },
    {
        "type_": "UP",
        "move_rule": UP,
        "val":  coordsValUp
    },
    {
        "type_": "DOWN",
        "move_rule": DOWN,
        "val":  coordsValBottom
    }
    ]
    for cl in coordsValList:
        if cl["val"] == 0:
            num_possibilities = num_possibilities + 1
        if cl["type_"] == "RIGHT" or cl["type_"] == "LEFT":
            moves_dict[cl["type_"]] = {
                    "x": x + cl["move_rule"],
                    "y": y,
                    "val": cl["val"]
            }
        elif cl["type_"] == "UP" or cl["type_"] == "DOWN":
            moves_dict[cl["type_"]] = {
                    "x": x,
                    "y": y + cl["move_rule"],
                    "val": cl["val"]
            }
    val, boolval = coordsKey
    x_opposite_val = 0
    y_opposite_val = 0
    x_original_val = 0
    y_original_val = 0
    move_key_matched = ""
    oppositeCoordsKey = ()
    if boolval is True:
        oppositeCoordsKey = (val, False)
        x_opposite_val, y_opposite_val = gridEnds[oppositeCoordsKey]
    elif boolval is False:
        oppositeCoordsKey = (val, True)
        x_opposite_val, y_opposite_val = gridEnds[oppositeCoordsKey]
    for moveKey in moves_dict.keys():
        y_original_val = moves_dict[moveKey]["y"]
        x_original_val = moves_dict[moveKey]["x"]
        move_key_matched = moveKey
        if y_opposite_val == y_original_val and x_opposite_val == x_original_val:
            hasEndNeighbor = True
            break

    if hasEndNeighbor is True and has_exclusion is False:
        if move_key_matched == "RIGHT":
            moves_dict.pop("LEFT", None)
        elif move_key_matched == "LEFT":
            moves_dict.pop("RIGHT", None)
        elif move_key_matched == "UP":
            moves_dict.pop("DOWN", None)
        elif move_key_matched == "DOWN":
            moves_dict.pop("UP", None)

    return {
        "num_possibilities": num_possibilities,
        "coordsKey": coordsKey,
        "coords": coords,
        "coordsVal": coordsVal,
        "moves": moves_dict,
        "hasEndNeighbor": hasEndNeighbor
    }


def get_list_of_next_movements(gridEnds: Ends, gridState: Grid):
    movements = []
    i = 0
    has_exclusion = False
    for gk, gv in gridEnds.items():
        move_dict = get_move_possibilities(gk, gv, gridEnds, gridState, has_exclusion)
        movements.append(move_dict)
        i = i + 1
    n = len(movements)
    for i in range(n-1):
        j = 0
        for _ in movements:
            if j + 1 < len(movements):
                if movements[j]["num_possibilities"] > movements[j + 1]["num_possibilities"]:
                    movements[j], movements[j +
                                            1] = movements[j + 1], movements[j]
            j = j + 1
    return movements

def get_opposite_end(val, bool_):
    if bool_ is True:
        return (val, False)
    return (val, True)

def check_map(gridEnds: Ends, gridState: Grid):
    connections_len = len(gridEnds.keys()) // 2
    connections = {}
    has_exclusion = True
    index = 0
    grid_ends_cpy = gridEnds.copy()
    for gk in gridEnds.keys():
        val, bool_ = gk
        gk_opo = get_opposite_end(val, bool_)
        x_v, y_v = gridEnds[gk]
        x_opo_v, y_opo_v = gridEnds[gk_opo]
        all_possibilities = get_move_possibilities(gk, (x_v, y_v), gridEnds, gridState, has_exclusion)
        ps_moves_keys =  all_possibilities["moves"].keys()
        if x_v == x_opo_v and y_v == y_opo_v:
            connections[gk] = {
                    "original": (x_v, y_v),
                    "val": val,
                    "oposite":(x_opo_v, y_opo_v)
                } 
        else:
            for ps_move in ps_moves_keys:
                move = all_possibilities["moves"][ps_move]
                if move["x"] == x_opo_v and move["y"] == y_opo_v:
                    connections[gk] = {
                        "original": (x_v, y_v),
                        "val": val,
                        "oposite":(x_opo_v, y_opo_v)
                    }
        index = index + 1
    
    for cnn in connections.keys():
        grid_ends_cpy.pop(cnn, None)

    if connections_len == len(connections.keys()) // 2:
        return {
            "is_valid_map": True,
            "connections": connections,
            "missing_connections": grid_ends_cpy,
        }
    return {
            "is_valid_map": False,
            "connections": connections,
            "missing_connections": grid_ends_cpy,
        }

def make_movement(gridEnds: Ends, gridState: Grid, game_status):
    movements = get_list_of_next_movements(gridEnds, gridState)
    moved_the_ones = False

    filtered_has_neighbor_movements = []
    filtered_has_not_neighbor_movements = []
    for movement in movements:
        if movement["hasEndNeighbor"] is True:
            filtered_has_neighbor_movements.append(movement)
        else:
            filtered_has_not_neighbor_movements.append(movement)

    if len(movements) - 2 == len(filtered_has_neighbor_movements):
        game_status["is_missing_only_one"] = True
    
    if game_status["is_missing_only_one"] is False:
        movements = filtered_has_not_neighbor_movements

    for movement in movements:
        moves = movement["moves"]
        moves_keys = movement["moves"].keys()
        coordsVal = movement["coordsVal"]
        coordsKey = movement["coordsKey"]
        num_possibilities = movement["num_possibilities"]
        if num_possibilities == 1:
            moved = False
            for val in moves_keys:
                if moves[val]["val"] == 0 and moved is False:
                    mov_x = moves[val]["x"]
                    mov_y = moves[val]["y"]
                    gridState[mov_y][mov_x] = coordsVal
                    gridEnds[coordsKey] = (mov_x, mov_y)
                    moved_the_ones = True
                    moved = True
                    print("===================================")
                    for i in gridState:
                        print(i)

    if len(movements) != 0 and moved_the_ones is False:
        moves = movements[0]["moves"]
        moves_keys = movements[0]["moves"].keys()
        coordsVal = movements[0]["coordsVal"]
        coordsKey = movements[0]["coordsKey"]
        num_possibilities = movements[0]["num_possibilities"]
        num_possibilities = movements[0]["num_possibilities"]
        if num_possibilities > 0:
            for val in moves_keys:
                if moves[val]["val"] == 0:
                    mov_x = moves[val]["x"]
                    mov_y = moves[val]["y"]
                    gridState[mov_y][mov_x] = coordsVal
                    gridEnds[coordsKey] = (mov_x, mov_y)
                    print("===================================")
                    for i in gridState:
                        print(i)
                    make_movement(gridEnds, gridState, game_status)
                    break
        elif num_possibilities == 0:
            print("THE END")

    elif moved_the_ones is True:
        make_movement(gridEnds, gridState, game_status)

def make_movement_2(gridEnds: Ends, gridState: Grid):
    game_status = {}
    game_status["is_missing_only_one"] = False
    make_movement(gridEnds, gridState, game_status)
    result = check_map(gridEnds, gridState)
    return result


def solve(grid: Grid) -> Optional[Grid]:
    grid_cpy = grid.copy()
    gridEnds = get_ends(grid_cpy)
    gridEndsCpy = gridEnds.copy()
    result = make_movement_2(gridEnds, grid_cpy)
    if result["is_valid_map"] is False:
        missing_connections = result["missing_connections"]
        for mc_k, _ in missing_connections.items():
            val, _ = mc_k
            index_y = 0
            for g in grid_cpy:
                index_x = 0
                for _ in g:
                    if g[index_x] == val:
                        is_gridend = False
                        for geck in gridEndsCpy.keys():
                            if gridEndsCpy[geck] == (index_x, index_y):
                                is_gridend = True
                        if is_gridend is False:
                            g[index_x] = 0
                    index_x = index_x + 1
                index_y = index_y + 1
        print("============ reset map ===========")
        for i in grid_cpy:
            print(i)
        print("============ reset map ===========")
        solve(grid_cpy)
    else:
        return grid_cpy

# «Poznámka» k volbě typu ‹Ends› pro reprezentaci „konců provázků“:
# Mnozí by jistě mohli navrhnout, že mít ve dvojicích klíčů arbitrární
# hodnoty ‹True› a ‹False› je zbytečné a že by se slovník „konců“ dal
# napsat jinak (např. s typem ‹Dict[int, Tuple[Position, Position]›).
# Zde zvolený typ má ale jistou symetrii, která je výhodná pro implementaci
# funkce ‹solve›. Ke všem „koncům“ se totiž chováme stejně, a tedy kód
# pro nalezení jednoho konkrétního (toho s nejméně možnostmi pohybu)
# stejně jako kód pro jeho posunutí můžeme napsat obecně a nemusíme u toho
# rozebírat více různých případů.


def main() -> None:

    # grid = [
    #     [1, 2, 3],
    #     [0, 0, 0],
    #     [0, 0, 0],
    #     [1, 2, 0],
    #     [0, 0, 0],
    #     [0, 0, 3],
    # ]

    # check_ends(grid, get_ends(grid))

    # assert solve(grid) == [
    #     [1, 2, 3],
    #     [1, 2, 3],
    #     [1, 2, 3],
    #     [1, 2, 3],
    #     [3, 3, 3],
    #     [3, 3, 3],
    # ]

    # grid = [
    #     [0, 0, 0, 4, 0, 0, 0],
    #     [0, 3, 0, 0, 2, 5, 0],
    #     [0, 0, 0, 3, 1, 0, 0],
    #     [0, 0, 0, 5, 0, 0, 0],
    #     [0, 0, 0, 0, 0, 0, 0],
    #     [0, 0, 1, 0, 0, 0, 0],
    #     [2, 0, 0, 0, 4, 0, 0],
    # ]

    # check_ends(grid, get_ends(grid))

    # assert solve(grid) == [
    #     [2, 2, 2, 4, 4, 4, 4],
    #     [2, 3, 2, 2, 2, 5, 4],
    #     [2, 3, 3, 3, 1, 5, 4],
    #     [2, 5, 5, 5, 1, 5, 4],
    #     [2, 5, 1, 1, 1, 5, 4],
    #     [2, 5, 1, 5, 5, 5, 4],
    #     [2, 5, 5, 5, 4, 4, 4],
    # ]

    # grid = [
    #     [1, 0, 0, 2],
    #     [2, 0, 0, 3],
    #     [3, 0, 0, 1],
    # ]

    # check_ends(grid, get_ends(grid))

    # assert solve(grid) is None

    # grid = [
    #     [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    #     [2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2],
    #     [3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3],
    #     [4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4],
    #     [5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5],
    #     [6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6],
    #     [7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7],
    # ]

    # check_ends(grid, get_ends(grid))

    # assert solve(grid) == [
    #     [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    #     [2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2],
    #     [3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3],
    #     [4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4],
    #     [5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5],
    #     [6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6],
    #     [7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7],
    # ]

    grid = [
        [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2],
        [0, 0, 3, 0, 4, 0, 5, 0, 6, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 4, 0, 0, 0, 0, 0, 0, 0, 7, 0],
        [0, 0, 0, 0, 8, 6, 3, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0, 0, 0, 0, 9, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 2, 0, 7, 0, 9, 0, 0, 0],
        [0, 8, 0, 0, 0, 0, 0, 0, 0, 5, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    ]

    check_ends(grid, get_ends(grid))

    assert solve(grid) == [
        [1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 2],
        [3, 3, 3, 4, 4, 1, 5, 6, 6, 5, 2],
        [3, 4, 4, 4, 1, 1, 6, 6, 5, 5, 2],
        [3, 4, 1, 1, 1, 6, 6, 5, 5, 7, 2],
        [3, 1, 1, 8, 8, 6, 3, 5, 7, 7, 2],
        [3, 1, 8, 8, 3, 3, 3, 5, 7, 9, 2],
        [3, 8, 8, 3, 3, 5, 5, 5, 7, 9, 2],
        [3, 8, 3, 3, 5, 5, 7, 7, 7, 9, 2],
        [3, 8, 3, 2, 5, 7, 7, 9, 9, 9, 2],
        [3, 8, 3, 2, 5, 5, 5, 5, 5, 5, 2],
        [3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2],
    ]

def check_ends(grid: Grid, ends: Ends) -> None:
    nums = set()
    for row in grid:
        nums.update(row)

    nums.remove(0)

    for num in nums:
        for b in True, False:
            assert (num, b) in ends
            x, y = ends[num, b]
            assert grid[y][x] == num

        assert ends[num, True] != ends[num, False]


if __name__ == '__main__':
    main()