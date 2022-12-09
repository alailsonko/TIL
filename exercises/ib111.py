# pylint: skip-file
# type: ignore

import builtins
from collections import deque

try:
    from typing import GenericAlias
except:
    GenericAlias = None


def make_generator():
    yield None


async def make_async():
    pass


_async = make_async()

generator = type(make_generator())
coroutine = type(_async)
function = type(lambda: ())
builtin_f = type(min)
module = type(builtins)
d_keys = type({}.keys())
d_items = type({}.items())
d_values = type({}.values())

#############################################################################
# the list of things to allow (configuration, basically)


def allow_functions():

    basics = {
        # we don't know how to patch those and probably don't want to
        "__class__",
        "__class_getitem__",
        "__subclasshook__",
        "__sizeof__",
        "__name__",
        "__qualname__",
        "__dir__",
        "__doc__",
        "__getattribute__",
        "__setattribute__",
        "__delattr__",
        "__setattr__",
        "__new__",
        "__getnewargs__",
        "__init__",
        "__init_subclass__",
        "__del__",
        # comparisons; leave alone
        "__eq__",
        "__ne__",
        "__lt__",
        "__le__",
        "__gt__",
        "__ge__",
        # we don't know how to patch these (mostly int/float stuff)
        "__ceil__",
        "__divmod__",
        "__floor__",
        "__invert__",
        "__radd__",
        "__rand__",
        "__rdivmod__",
        "__rfloordiv__",
        "__rlshift__",
        "__rmod__",
        "__rmul__",
        "__ror__",
        "__round__",
        "__rpow__",
        "__rrshift__",
        "__rsub__",
        "__rtruediv__",
        "__rxor__",
        "__trunc__",
        # sequence stuff not known
        "__reversed__",
        "__next__",
        "__reduce__",
        "__reduce_ex__",
        # implemented as __setitem__, which is really hard to wrap or disable
        # (at least) for lists; we instead disallow 'del foo' entirely
        "__delitem__",
        # required for normal functioning of things
        "__bool__",
        "__hash__",
    }

    allow = is_allowed.list = {}

    allow[int] = basics | {
        "__add__",
        "__sub__",
        "__mod__",
        "__floordiv__",
        "__neg__",
        "__abs__",
        "__mul__",
        "__pow__",
        "__float__",
        "__truediv__",  # wrapped
        "__or__",  # wrapped
    }

    allow[float] = basics | {
        "__add__",
        "__sub__",
        "__truediv__",
        "__neg__",
        "__abs__",
        "__mul__",
        "__pow__",
        "__int__",
        "__getformat__",
        "__setformat__",  # internal float machinery
        "__get_format__",
        "__set_format__",  # same but for 3.9.10 and older
    }

    allow[str] = basics | {"__repr__"}
    allow[list] = basics | {"__getitem__", "__iter__"}
    allow[dict] = basics | {"__getitem__", "__setitem__", "__len__", "keys"}
    allow[set] = basics
    allow[deque] = basics

    allow[d_keys] = basics | {"__iter__"}
    allow[d_items] = basics | {"__iter__"}
    allow[d_values] = basics

    allow[generator] = basics
    allow[coroutine] = basics
    allow[builtins] = {
        "min",
        "max",
        "abs",
        "print",
        "__import__",
        "range",
        "round",
        "float",
        "AssertionError",
        "AttributeError",
        "__name__",  # overriding builtins.__name__ makes things very confusing
        "hasattr",  # killed by overrides_late()
        "tuple",  # likewise
    }

    if level >= 3:
        allow[int] |= {"__divmod__"}
        allow[list] |= {"__len__", "__setitem__", "append", "pop", "copy"}
        allow[builtins] |= {"list", "len", "sum", "enumerate", "divmod"}

    if level >= 4:
        allow[str] |= {
            "__getitem__",
            "__iter__",
            "__len__",
            "__format__",
            "isupper",
            "islower",
            "isalpha",
            "isdecimal",
            "upper",
            "lower",
            "split",
            "join",
            "replace",
            "rstrip",
        }
        allow[int] |= {"__str__", "__repr__", "__format__"}
        allow[float] |= {"__str__", "__format__"}
        allow[builtins] |= {"int", "chr", "ord", "str", "input", "format"}

    if level >= 5:
        allow[str] |= {"strip", "startswith"}

    if level >= 6:
        allow[set] |= {
            "__contains__",
            "__iter__",
            "__len__",
            "copy",
            "add",
            "remove",
            "__or__",
            "__and__",
            "__sub__",
            "update",
            "intersection_update",
            "difference_update",
        }
        allow[list] |= {
            "reverse",
            "__contains__",
            "index",
            "__add__",
            "extend",
            "insert",
        }
        allow[builtins] |= {"set", "dict"}

        allow[dict] |= {"__contains__", "keys", "values", "items", "get", "pop", "copy"}
        allow[deque] |= {"append", "popleft"}
        allow[d_keys] |= {"__len__"}
        allow[d_items] |= {"__len__"}
        allow[d_values] |= {"__iter__", "__len__"}

    if level >= 7:
        allow[builtins] |= {"__build_class__"}

    if level >= 8:
        allow[builtins] |= {"sorted"}
        allow[list] |= {"sort"}

    if level >= 10:
        allow[builtins] |= {"isinstance"}

    if level >= 11:
        allow[builtins] |= {"open", "any"}
        allow[str] |= {"__contains__", "splitlines", "translate", "isalnum", "index"}
        allow[dict] |= {"setdefault", "items"}

    if level >= 12:
        allow[list] |= {"count"}


def allow_modules():
    allow = wrap_import.allow = {}

    allow["quick"] = [
        "nat",
        "nat1",
        "nat2",
        "char",
        "assert_eq",
        "delay",
        "oneof",
        "small",
        "mixed",
        "fixed",
        "qgen",
        "sequence",
        "to_test",
        "distribution",
        "generator",
        "fmt_value",
    ]
    allow["turtle"] = [
        "+forward",
        "+backward",
        "+right",
        "+left",
        "+setheading",
        "+done",
        "+speed",
        "+delay",
        "+penup",
        "+pendown",
    ]
    allow["mp_turtle"] = allow["turtle"]
    allow["threading"] = []

    allow["math"] = [
        "pi",
        "acos",
        "cos",
        "asin",
        "sin",
        "atan",
        "atan2",
        "tan",  # trig
        "sqrt",
        "isqrt",  # roots
        "degrees",
        "radians",  # angles
        "trunc",
        "floor",
        "ceil",  # rounding
        "isclose",
    ]

    if level >= 2:
        allow["math"] += ["factorial"]

    if level >= 5:
        allow["fractions"] = ["Fraction"]
        allow["typing"] = ["List", "Tuple", "Optional", "Annotated"]
        allow["math"] += ["gcd", "lcm"]  # FIXME?

    if level >= 6:
        allow["collections"] = ["deque"]
        allow["typing"] += ["Set", "Dict", "Deque"]

    if level >= 10:
        allow["typing"] += ["Union"]

    if level >= 11:
        allow["typing"] += ["TextIO"]
        allow["gzip"] = ["+open"]
        allow["http.client"] = ["HTTPSConnection"]
        allow["re"] = ["+findall", "+match", "+compile"]
        allow["zipfile"] = ["ZipFile", "+is_zipfile"]
        allow["io"] = ["BytesIO"]
        allow["glob"] = ["+glob"]
        allow["sys"] = ["stderr", "argv"]
        allow["csv"] = ["reader"]
        allow["datetime"] = ["date", "datetime", "timedelta", "time"]
        allow["calendar"] = ["monthrange"]
        allow["json"] = ["+load"]
        allow["shutil"] = ["+rmtree", "+copyfile", "+copy"]
        allow["os"] = [
            "path",
            "remove",
            "getcwd",
            "mkdir",
            "listdir",
            "+makedirs",
            "chdir",
            "scandir",
        ]


#############################################################################
# implementation follows

for _ in _async.__await__():
    pass  # shut up a warning

import ast
import os
import ctypes
from sys import settrace, gettrace, modules, exit, stderr, flags, exc_info
from gc import get_referents
from inspect import stack
from re import fullmatch
from abc import ABCMeta

#############################################################################
# first of all, back up things we are going to need but might patch away

_gen_iter_meth = generator.__iter__
_type = type
_list_iter = list.__iter__
_list_len = list.__len__
_list_getitem = list.__getitem__
_list_append = list.append
_list_pop = list.pop
_tuple_len = tuple.__len__
_tuple_getitem = tuple.__getitem__
_tuple_iter = tuple.__iter__
_dict_get = dict.get
_dict_getitem = dict.__getitem__
_dict_setitem = dict.__setitem__
_dict_keys = dict.keys
_dict_contains = dict.__contains__
_dict_items = dict.items
_dict_str = dict.__str__
_set_contains = set.__contains__
_set_add = set.add
_str_split = str.split
_str_join = str.join
_print = print
_str = str
_str_endswith = str.endswith
_str_startswith = str.startswith
_int = int
_set = set
_list = list
_dict = dict
_tuple = tuple
_getattr = getattr
_setattr = setattr
_hasattr = hasattr
_id = id
_dir = dir
_isinstance = isinstance


class _gen_iter:
    def __init__(self, gen):
        self.gen = gen

    def __iter__(self):
        return _gen_iter_meth(self.gen)


def is_dunder(name):
    return (
        _str_startswith(name, "__")
        and _str_endswith(name, "__")
        and name != "__format__"
        and name != "__copy__"
        and name != "__getstate__"
    )


#############################################################################
# what follows is machinery for patching interpreter's C objects, so that
# we can override dunders on built-in classes; builds on the ‹forbiddenfruit›
# pypi package, which is (c) 2013-2020 Lincoln de Sousa <lincoln@clarete.li>
# released under the MIT licence

c_pyobject = ctypes.py_object
c_int = ctypes.c_int
c_int32 = ctypes.c_int32
c_int64 = ctypes.c_int64
c_void_p = ctypes.c_void_p
c_ptr = ctypes.POINTER
c_ssize_t = c_int64 if ctypes.sizeof(c_void_p) == 8 else c_int32

c_toint = ctypes.CFUNCTYPE(c_int, c_pyobject)
c_toint64 = ctypes.CFUNCTYPE(c_int64, c_pyobject)
c_unary = ctypes.CFUNCTYPE(c_pyobject, c_pyobject)
c_binary = ctypes.CFUNCTYPE(c_pyobject, c_pyobject, c_pyobject)
c_ternary = ctypes.CFUNCTYPE(c_pyobject, c_pyobject, c_pyobject, c_pyobject)
c_len_f = ctypes.CFUNCTYPE(c_ssize_t, c_pyobject)
c_index_f = ctypes.CFUNCTYPE(c_pyobject, c_pyobject, c_ssize_t)
c_iassign_f = ctypes.CFUNCTYPE(c_int, c_pyobject, c_ssize_t, c_pyobject)
c_new_f = ctypes.CFUNCTYPE(c_pyobject, c_pyobject, c_pyobject, c_void_p)

cfunc_refs = []
cfunc_exception = None
cfunc_rethrow = False


def make_struct(methods):
    class table(ctypes.Structure):
        _fields_ = [(n, t) for _, n, t in methods]

    return table


tab_number = [
    ("add", "nb_add", c_binary),
    ("sub", "nb_subtract", c_binary),
    ("mul", "nb_multiply", c_binary),
    ("mod", "nb_remainder", c_binary),
    (None, "nb_divmod", c_binary),
    ("pow", "nb_power", c_binary),
    ("neg", "nb_negative", c_unary),
    ("pos", "nb_positive", c_unary),
    ("abs", "nb_absolute", c_unary),
    ("bool", "nb_bool", c_toint),
    ("inv", "nb_invert", c_unary),
    ("lshift", "nb_lshift", c_binary),
    ("rshift", "nb_rshift", c_binary),
    ("and", "nb_and", c_binary),
    ("xor", "nb_xor", c_binary),
    ("or", "nb_or", c_binary),
    ("int", "nb_int", c_unary),
    (None, "nb_reserved", c_void_p),
    ("float", "nb_float", c_unary),
    ("iadd", "nb_inplace_add", c_binary),
    ("isub", "nb_inplace_subtract", c_binary),
    ("imul", "nb_inplace_multiply", c_binary),
    ("imod", "nb_inplace_remainder", c_binary),
    ("ipow", "nb_inplace_power", c_ternary),
    ("ilshift", "nb_inplace_lshift", c_binary),
    ("irshift", "nb_inplace_rshift", c_binary),
    ("iand", "nb_inplace_and", c_binary),
    ("ixor", "nb_inplace_xor", c_binary),
    ("ior", "nb_inplace_or", c_binary),
    ("floordiv", "nb_floor_divide", c_binary),
    ("truediv", "nb_true_divide", c_binary),
    ("ifloordiv", "nb_inplace_floor_divide", c_binary),
    ("itruediv", "nb_inplace_true_divide", c_binary),
    ("index", "nb_index", c_binary),
    ("matmul", "nb_matrix_multiply", c_binary),
    ("imatmul", "nb_inplace_matrix_multiply", c_binary),
]

tab_sequence = [
    ("len", "sq_length", c_len_f),
    ("add", "sq_concat", c_binary),
    ("mul", "sq_repeat", c_index_f),
    ("getitem", "sq_item", c_index_f),
    (None, "was_sq_slice", c_void_p),
    ("setitem", "sq_ass_item", c_iassign_f),
    (None, "was_sq_ass_slice", c_void_p),
    ("contains", "sq_contains", c_binary),
    ("iadd", "sq_inplace_concat", c_binary),
    ("imul", "sq_inplace_repeat", c_index_f),
]

tab_async = [
    ("await", "am_await", c_unary),
    ("aiter", "am_aiter", c_unary),
    ("anext", "am_anext", c_unary),
]

tab_mapping = [
    ("len", "mp_length", c_len_f),
    ("getitem", "mp_subscript", c_binary),
    ("setitem", "mp_ass_subscript", c_ternary),
]

tab_buffer = []

struct_number = make_struct(tab_number)
struct_sequence = make_struct(tab_sequence)
struct_mapping = make_struct(tab_mapping)
struct_async = make_struct(tab_async)
struct_buffer = make_struct(tab_async)

tab_pyobject = [
    (None, "ob_refcnt", c_ssize_t),
    (None, "ob_type", c_void_p),
    (None, "ob_size", c_ssize_t),
    (None, "tp_name", c_void_p),
    (None, "tp_basicsize", c_ssize_t),
    (None, "tp_itemsize", c_ssize_t),
    (None, "tp_dealloc", c_void_p),
    (None, "printfunc", c_void_p),
    (None, "getattrfunc", c_void_p),
    (None, "setattrfunc", c_void_p),
    (None, "tp_as_async", c_ptr(struct_async)),
    ("repr", "tp_repr", c_unary),
    (None, "tp_as_number", c_ptr(struct_number)),
    (None, "tp_as_sequence", c_ptr(struct_sequence)),
    (None, "tp_as_mapping", c_ptr(struct_mapping)),
    ("hash", "tp_hash", c_toint64),
    ("call", "tp_call", c_ternary),
    ("str", "tp_str", c_unary),
    (None, "tp_getattro", c_void_p),
    ("setattribute", "tp_setattro", c_binary),
    (None, "tp_as_buffer", c_void_p),
    (None, "tp_flags", c_void_p),
    (None, "tp_doc", c_void_p),
    (None, "tp_traverse", c_void_p),
    (None, "tp_clear", c_void_p),
    (None, "tp_richcompare", c_void_p),
    (None, "tp_weaklistoffset", c_void_p),
    ("iter", "tp_iter", c_unary),
    (None, "iternextfunc", c_void_p),
    (None, "tp_methods", c_void_p),
    (None, "tp_members", c_void_p),
    (None, "tp_getset", c_void_p),
    (None, "tp_base", c_void_p),
    (None, "tp_dict", c_void_p),
    (None, "tp_descr_get", c_void_p),
    (None, "tp_descr_set", c_void_p),
    (None, "tp_dictoffset", c_void_p),
    (None, "tp_init", c_void_p),
    (None, "tp_alloc", c_void_p),
    ("new", "tp_new", c_new_f),
]

struct_pyobject = make_struct(tab_pyobject)
dunders = {}

for name, cname, ctype in tab_pyobject:

    def get_func(cklass, cname=cname, ctype=ctype):
        yield cklass, cname, ctype

    dunders[f"__{name}__"] = get_func


def add_dunders(tab, struct, field):
    for name, cname, ctype in tab:

        def get_func(cklass, cname=cname, ctype=ctype, field=field):
            ptr = _getattr(cklass, field)
            if ptr:
                yield (ptr[0], cname, ctype)

        if f"__{name}__" in dunders:

            def try_both(cklass, first=dunders[f"__{name}__"], second=get_func):
                yield from _gen_iter(first(cklass))
                yield from _gen_iter(second(cklass))

            dunders[f"__{name}__"] = try_both
        else:
            dunders[f"__{name}__"] = get_func


add_dunders(tab_number, struct_number, "tp_as_number")
add_dunders(tab_sequence, struct_sequence, "tp_as_sequence")
add_dunders(tab_mapping, struct_mapping, "tp_as_mapping")
add_dunders(tab_async, struct_async, "tp_as_async")
add_dunders(tab_buffer, struct_buffer, "tp_as_buffer")


def patch(klass, attr, value):
    new, restore, call = value, None, None
    pyattr = "__getitem__" if attr == "__subscript__" else attr

    if _id(klass) == _id(builtins):
        restore = call = _getattr(builtins, attr)
        _setattr(builtins, attr, value)
    elif is_dunder(attr):
        cklass = struct_pyobject.from_address(_id(klass))

        for patch_ in _gen_iter(_dict_getitem(dunders, pyattr)(cklass)):
            patch_obj = _tuple_getitem(patch_, 0)
            patch_field = _tuple_getitem(patch_, 1)
            patch_type = _tuple_getitem(patch_, 2)

            # for tuple, we only want to ever patch struct_mapping; the sequence methods of tuple
            # are used internally by ctypes, which gives us fireworks
            if patch_obj.__class__ is struct_sequence:
                if klass is _tuple or attr == "__subscript__":
                    continue

            if _isinstance(value, function):

                def cfunc_noexcept(*args, **kwargs):
                    try:
                        rv = value(*args, **kwargs)
                    except:
                        global cfunc_exception
                        err = _tuple_getitem(exc_info(), 1)
                        if cfunc_rethrow:
                            cfunc_exception = err
                        else:
                            _error(err, " (", err.__class__.__name__, ")")
                        rv = None
                    if rv is None:
                        none = struct_pyobject.from_address(_id(None))
                        none.ob_refcnt += 1
                    return rv

                cfunc = patch_type(cfunc_noexcept)
                _list_append(cfunc_refs, cfunc)  # keep the function object alive
                new = cfunc
            else:
                cfunc = value

            restore = _getattr(patch_obj, patch_field)

            if restore:
                restore = ctypes.cast(restore, patch_type)
            else:
                continue

            if _hasattr(klass, pyattr):
                call = _getattr(klass, pyattr)
            else:
                call = restore

            _setattr(patch_obj, patch_field, cfunc)
            break
    else:
        patchable = _list_getitem(get_referents(klass.__dict__), 0)
        restore = call = _dict_get(patchable, attr)
        _dict_setitem(patchable, attr, value)

    return new, restore, call


def patch_clear_cache():
    ctypes.pythonapi.PyType_ClearCache()


def wrap(klass, attr, func):
    old = None

    def with_patched(*args, **kwargs):
        return func(attr, old, *_tuple_iter(args), **kwargs)

    patched = patch(klass, attr, func if _isinstance(func, _type) else with_patched)
    new = _tuple_getitem(patched, 0)
    old = _tuple_getitem(patched, 2)
    return new, _tuple_getitem(patched, 1)


overrides = []
originals = []
enabled = []
override_set = set()


def override(klass, attr, value):
    wrap_ = wrap(klass, attr, value)
    _list_append(overrides, (klass, attr, _tuple_getitem(wrap_, 0)))
    _list_append(originals, (klass, attr, _tuple_getitem(wrap_, 1)))
    assert not _set_contains(override_set, (klass, attr))
    _set_add(override_set, (klass, attr))


def switch_state(want_enabled, enter):
    def is_enabled():
        return not _list_len(enabled) or _list_getitem(enabled, -1)

    if enter:
        was_enabled = is_enabled()
        _list_append(enabled, want_enabled)
        return was_enabled != want_enabled
    else:
        if _list_pop(enabled) == want_enabled:
            _print("switch_state mismatch")
            os._exit(1)

        return is_enabled() == want_enabled


def overrides_disable(enter=True):
    if switch_state(False, enter):
        settrace(None)
        for kav in _list_iter(originals):
            k, a, v = _tuple_iter(kav)
            patch(k, a, v)
        patch_clear_cache()


def overrides_enable(enter=False):
    if switch_state(True, enter):
        for kav in _list_iter(overrides):
            k, a, v = _tuple_iter(kav)
            patch(k, a, v)
        patch_clear_cache()
        settrace(monitor)


class overrides_disabled:
    def __enter__(self):
        overrides_disable(True)

    def __exit__(self, typ, val, tb):
        overrides_enable(False)


class overrides_enabled:
    def __enter__(self):
        overrides_enable(True)

    def __exit__(self, typ, val, tb):
        overrides_disable(False)


#############################################################################
# sentinel objects to be imported

week_00 = ()
week_01 = ()
week_02 = ()
week_03 = ()
week_04 = ()
week_05 = ()
week_06 = ()
week_07 = ()
week_08 = ()
week_09 = ()
week_10 = ()
week_11 = ()
week_12 = ()

#############################################################################
# global information about the script

this_file = stack(0)[0].filename
level = None
level_str = None
script = None
code = None
badlines = {}
gdict = {}

#############################################################################
# dunder overrides need to be callable from C and as such cannot raise
# exceptions; kill the interpreter the old-fashioned way

error_called = False


def error_print(trace, *args):
    print("traceback:", file=stderr)
    for frame in reversed(trace):
        print(
            f"    {frame.filename}, line {frame.lineno} in {frame.function}",
            file=stderr,
        )
    print("error: ", *args, file=stderr, sep="")


def _error(*args):
    global error_called

    if error_called:
        _print("nested error: ", *args)
        os._exit(1)

    error_called = True

    with overrides_disabled():
        error_print([f for f in stack(0) if f.filename != this_file], *args)
        os._exit(1)


#############################################################################
# actual overrides


def refuse_method(attr, old, self, *args):
    name = self.__class__.__name__
    classes = []
    for arg in args:
        _list_append(classes, arg.__class__.__name__)
    _error(f"{name}.{attr}({_str_join( ', ', classes )}) is disabled")


def refuse_builtin(attr, old, *args):
    _error(f"the built-in function {attr} is disabled")


def wrap_function(attr, old, *args, **kwargs):
    with overrides_disabled():
        return old(*args, **kwargs)


class module_proxy:
    pass


def import_hacks(old, name, *args, **kwargs):
    if name == "io":
        # when printing a stack trace, python repeatedly calls 'import io'
        # with an empty stack (i.e. the only things on the stack is the
        # override machinery) – allow those imports to prevent messing up
        # the traces
        old(name, *args, **kwargs)
        return object()

    return None


def without_overrides(func):
    def wrap(*args, **kwargs):
        with overrides_disabled():
            return func(*args, **kwargs)

    return wrap


def wrap_attr(klass, attr):
    _setattr(klass, attr, without_overrides(_getattr(klass, attr)))


def make_proxy(mod_name, mod, allow):
    proxy = module_proxy()
    proxy.__name__ = mod_name

    if mod_name == "typing":
        wrap_attr(mod.List.__class__, "__getitem__")
        wrap_attr(mod.Union.__class__, "__getitem__")
        wrap_attr(mod.Tuple.__class__, "__getitem__")
        if hasattr(mod, "Annotated"):
            wrap_attr(mod.Annotated, "__class_getitem__")
    if mod_name == "http.client":
        wrap_attr(mod.HTTPConnection, "request")
        wrap_attr(mod.HTTPConnection, "getresponse")
        wrap_attr(mod.HTTPSConnection, "__init__")
        wrap_attr(mod.HTTPResponse, "close")
        wrap_attr(mod.socket.socket, "__repr__")
    if mod_name == "zipfile":
        wrap_attr(mod.ZipFile, "__init__")
        wrap_attr(mod.ZipFile, "read")
        wrap_attr(mod.ZipFile, "open")
        wrap_attr(mod.ZipFile, "close")
        wrap_attr(mod.ZipFile, "extractall")
        wrap_attr(mod.ZipFile, "writestr")
        wrap_attr(mod.ZipFile, "__exit__")
        wrap_attr(mod.ZipExtFile, "close")
    if mod_name == "gzip":
        wrap_attr(mod.GzipFile, "read1")
        wrap_attr(mod.GzipFile, "close")
    if mod_name == "os":
        wrap_attr(mod.path, "join")
        wrap_attr(mod.path, "split")
        wrap_attr(mod.path, "exists")
        wrap_attr(mod.path, "splitext")
        wrap_attr(mod.path, "basename")
    if mod_name == "fractions":
        wrap_attr(mod.Fraction, "__new__")
        wrap_attr(mod.Fraction, "__eq__")
        wrap_attr(mod.Fraction, "__add__")
        wrap_attr(mod.Fraction, "__mul__")

    for item in allow:
        wrap = item[0] == "+"
        name = item[1:] if wrap else item
        if _hasattr(mod, name):
            obj = _getattr(mod, name)
            if wrap:
                wrap_attr(mod, name)
            _setattr(proxy, name, _getattr(mod, name))

    return proxy


def wrap_import(attr, old, name, *args, **kwargs):
    with overrides_disabled():

        if flags.interactive and name in [
            "sys",
            "atexit",
            "readline",
            "rlcompleter",
            "pydoc",
        ]:
            return old(name, *args, **kwargs)

        hack = import_hacks(old, name, *args, **kwargs)
        allow = wrap_import.allow.get(name)

        if hack is not None:
            return hack

        if fullmatch("^[deprs][0-9]_[a-z]+", name):
            return old(name, *args, **kwargs)
        if allow is not None:
            return make_proxy(name, old(name, *args, **kwargs), allow)

        return _error("refusing import of ", name)


def wrap_int_or(attr, old, self, other):
    if other != 1:
        _error("int.__or__(int) is disabled")
    return old(self, other)


def wrap_list_pop(attr, old, self, *args, **kwargs):
    if _tuple_len(args) or kwargs:
        _error("pop() with a parameter is disabled")
    return old(self)


def wrap_list_getitem(attr, old, self, arg):
    if not _isinstance(arg, _int):
        _error("lists can only be indexed using integers")
    return old(self, arg)


def wrap_truediv(attr, old, self, arg):
    if not _isinstance(arg, float):
        _error("at least one argument of / must be a float")
    return old(self, arg)


class wrap_list(list):
    def __init__(self, *args):
        if _tuple_len(args) == 1 and _isinstance(_tuple_getitem(args, 0), _tuple):
            _error("construction of lists from tuples is disabled")
        _list.__init__(self, *args)


class refuse_tuple(tuple):
    def __init__(self, *args):
        _error("the built-in function tuple() is disabled")


# on python 3.7, we have to delay applying some of the overrides until after
# importlib is done; as soon as we get away with requiring 3.8, these can be
# probably merged (importlib no longer seems to mess around nearly as much
# after the eval)


def is_allowed(klass, name):
    return _set_contains(_dict_getitem(is_allowed.list, klass), name)


def override_class(klass):
    for method in _dir(klass):
        if not is_allowed(klass, method):
            refuse = refuse_builtin if klass is builtins else refuse_method
            override(klass, method, refuse)
    patch_clear_cache()


def overrides_late():

    for klass in (d_keys, d_items, d_values, _dict, _str, _list, generator, builtins):
        override_class(klass)

    override(function, "__setattribute__", refuse_method)
    override(_tuple, "__contains__", refuse_method)
    override(_tuple, "__getitem__", refuse_method)
    override(_tuple, "__len__", refuse_method)
    override(builtins, "hasattr", refuse_builtin)
    override(_int, "__truediv__", wrap_truediv)
    override(_int, "__or__", wrap_int_or)

    if level < 10:
        override(builtins, "tuple", refuse_tuple)

    if level >= 3:
        if level < 6:
            override(_list, "pop", wrap_list_pop)
        override(_list, "__getitem__", wrap_list_getitem)
        override(_list, "__subscript__", wrap_list_getitem)
        override(builtins, "list", wrap_list)

    if level >= 4:
        override(builtins, "input", wrap_function)

    patch_clear_cache()


# the rest kicks in immediately on import


def overrides_early():
    override(builtins, "print", wrap_function)
    override(builtins, "__import__", wrap_import)

    if not is_allowed(str, "__getitem__"):
        override(_str, "__subscript__", refuse_method)

    if is_allowed(builtins, "open"):
        override(builtins, "open", wrap_function)

    for klass in (_int, _set, float, coroutine, deque):
        override_class(klass)


#############################################################################
# global mutable state


def freeze_globals():
    if _hasattr(freeze_globals, "frozen"):
        _error("re-entered main")

    with overrides_disabled():
        from copy import deepcopy

        frozen = freeze_globals.frozen = {}

        for name, obj in gdict.items():
            if is_dunder(name) or name in (f"week_{level_str}", "_code"):
                continue

            if type(obj) in [type, function, builtin_f, module_proxy, ABCMeta, module]:
                continue
            if type(obj).__module__ == "typing":
                continue

            if type(obj) in [dict, list, tuple, str, int, float, GenericAlias]:
                frozen[name] = deepcopy(obj)
            else:
                _error(f"global {name} of type {type(obj)} is not allowed")


def check_globals():
    if not _hasattr(freeze_globals, "frozen") or not freeze_globals.frozen:
        return

    frozen = freeze_globals.frozen

    for n, obj in _dict_items(frozen):
        if gdict[n] != obj:
            _error(f"global variable {n} has been modified")


def check_periodic():
    pass


#############################################################################
# deferred initialization and trace-based monitoring


def initialize():
    if _hasattr(initialize, "done"):
        return

    initialize.done = ()
    overrides_late()


def restrict_trace(frame, why, arg):
    func = frame.f_code.co_name

    global cfunc_exception
    if cfunc_exception is not None:
        throw = cfunc_exception
        cfunc_exception = None
        raise throw

    if _dict_contains(badlines, frame.f_lineno):
        _error(badlines[frame.f_lineno])

    check_globals()
    check_periodic()

    if func == "<module>" and why == "return":
        overrides_disable()


def monitor(frame, why, arg):
    in_file = frame.f_code.co_filename
    func = frame.f_code.co_name

    if func == "main" and why == "call":
        freeze_globals()

    if in_file == script:
        initialize()
        restrict_trace(frame, why, arg)
        return restrict_trace


#############################################################################
# check that we have been imported correctly and figure out the
# level of restriction


def check_import():
    from os import environ

    global level, level_str, script, code, gdict

    line = None

    for frame in stack(0):
        if frame.lineno == 1:
            frame.frame.f_trace = restrict_trace
            script = frame.filename
            gdict = frame.frame.f_globals
            if script == "<string>":
                code = gdict["_code"]
            else:
                code = list(open(script, encoding="utf-8"))
            line = code[0]
            break

    if line is None:
        _error(f"{__name__} must be imported from the first line of your script")
        exit(1)

    matched = fullmatch(f"from {__name__} import week_(..)(  # noqa|)\n", line)

    if matched is None:
        _error(
            f"wrong import of {__name__}: {line}"
            + f"must be instead imported as: from {__name__} import week_NN"
        )
        exit(1)

    level_str = matched[1]
    level_env = environ.get("PYTHON_RESTRICT")
    level = int(level_str)

    if level_env is not None and level > int(level_env):
        _error(f"requested level mismatch: at most {level_env} is allowed")
        exit(1)


def check_ast(node, in_def=False, in_class=False, in_assign=False):
    result = None
    assign_to = []

    def bad(error, n=None, inherit=False):
        badlines[(node if n is None else n).lineno] = error
        if inherit:
            nonlocal result
            result = error

    def node_is(*classes):
        for cls in classes:
            if isinstance(node, cls):
                return True
        return False

    # ban use of dunders

    if node_is(ast.Name):
        if node.id.startswith("__") and node.id != "__name__":
            bad("using names that start with __ is not allowed")

    if node_is(ast.Attribute):
        if node.attr.startswith("__") and (
            node.attr.endswith("__")
            or not isinstance(node.value, ast.Name)
            or node.value.id not in ["self", "other"]
        ):
            bad("using names that start with __ is not allowed")

    # literals and comprehensions

    if node_is(ast.Dict) and level < 6:
        bad("dict is disabled")
    if node_is(ast.Set) and level < 6:
        bad("set is disabled")
    if node_is(ast.List) and level < 3:
        bad("list is disabled")
    if node_is(ast.Tuple) and level < 3:
        bad("tuple is disabled")

    if node_is(ast.ListComp) and level < 3:
        bad("list comprehensions are disabled")
    if node_is(ast.SetComp, ast.DictComp):
        bad("set and dict comprehensions are disabled")

    # expressions

    if node_is(ast.GeneratorExp):
        bad("generator expressions are disabled")
    if node_is(ast.Await):
        bad("await is disabled")
    if node_is(ast.JoinedStr):
        bad("f-strings are disabled")
    if node_is(ast.Starred):
        bad("starred expressions are disabled")
    if node_is(ast.Slice):
        if in_assign:
            bad("assigning to slices is not allowed")
        if not node.lower or node.step:
            bad("only slices of the form [a:b] or [a:] are allowed")
    if node_is(ast.Call):
        if not hasattr(node.func, "id") or node.func.id != "print":
            if node.keywords:
                bad("keyword arguments are only allowed for print()")
    if hasattr(ast, "NamedExpr") and node_is(ast.NamedExpr):
        bad("named expressions (x := …) are disabled")

    # statements

    if node_is(ast.Try, ast.Raise):
        bad("exceptions are disabled")
    if node_is(ast.FunctionDef, ast.Lambda):
        if in_def:
            bad("closures are disabled")
        if node.args.defaults:
            bad("default argument values are disabled")
        in_def = True
    if node_is(ast.ClassDef):
        if in_def or in_class:
            bad("nested classes are disabled")
        in_class = True
    if node_is(ast.AsyncFunctionDef, ast.AsyncFor, ast.AsyncWith):
        bad("async is disabled")
    if node_is(ast.Delete):
        bad("del is disabled")
    if node_is(ast.While, ast.For):
        if node.orelse:
            for stmt in [node] + node.body + node.orelse:
                bad("loops with else clauses are disabled", stmt)
    if node_is(ast.With) and level < 10:
        bad("with is disabled")
    if node_is(ast.Nonlocal, ast.Global):
        bad("nonlocal and global are disabled", inherit=True)
    if hasattr(ast, "Match") and node_is(ast.Match):
        bad("pattern matching is disabled")
    if node_is(ast.Assign):
        assign_to = node.targets

    if node_is(ast.Ellipsis) and level < 10:  # FIXME
        _error(f"line {node.lineno}: using an ellipsis is not allowed")

    # recurse

    for child in ast.iter_child_nodes(node):
        inherit = check_ast(child, in_def, in_class, in_assign or child in assign_to)
        if inherit:
            bad(inherit)

    return result


if gettrace():
    print("debugger detected, disabling restrictions")
else:
    check_import()
    check_ast(ast.parse("".join(code), script))

    allow_functions()
    allow_modules()

    for info in reversed(stack(0)):
        if info.filename == script:
            info.frame.f_trace = monitor

    overrides_early()
    settrace(monitor)