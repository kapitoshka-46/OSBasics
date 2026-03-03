# execve
execve("./hello.out", ["./hello.out"], 0x7ffec498ab30 /* 83 vars */) = 0

- Запускает программу по пути из 1-го аргумента. Новая программа появляется на месте старой ?
- Аргумнеты
1. "./hello.out" - путь до исполняемого файла
2. ["./hello.out] - массив argv
3. адрес - адрес, где лежат все переменные окружения (в программе можно принять как const char* envp[]);


# brk
brk(NULL)                               = 0x559138b51000
- Изменяет конец сегмента DATA (в ней как раз heap) у текущего процесса 

access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)

# openat
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3

- Аргументы
1. AT_FDCWD = At file fecriptor current work directory - 
использовать текущий рабочий каталог процесса для поиска файлов

2. путь

3. флаги открытия. O_RDONLY - readonly. O_CLOEXEC - автоматически закрыть файл, если текущий процесс вызовет execve.


fstat(3, {st_mode=S_IFREG|0644, st_size=212003, ...}) = 0

# mmap()
```c
void *mmap(void addr[length], size_t length, int prot, int flags,
            int fd, off_t offset);
```
- Подгружает файл в оперативочку
- Аргументы
1. addr - куда подгружать (ядро воспринимает это как совет. 
если место уже кто-то занял, то ядро само выберет, куда загрузить). 
если `addr==NULL`, то ядро выбирает page-aligned адрес
2. length - сколько байт отображать. > 0
3. prot - potection флаги 
    1) PROT_EXEC - на исполнение 
    2) PROT_READ - на чтение
    3) PROT_WRITE - на запист
    4) PRON_NONE - никакого доступа
4. flags - флаги непосредственно самой замапленной памяти. 
    1) 

`mmap(NULL, 212003, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fbd5fbef000`



close(3)                                = 0
openat(AT_FDCWD, "/usr/lib/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0y\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 896, 64) = 896
fstat(3, {st_mode=S_IFREG|0755, st_size=2149504, ...}) = 0
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fbd5fbed000
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 896, 64) = 896
mmap(NULL, 2173808, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7fbd5f800000
mmap(0x7fbd5f824000, 1511424, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x24000) = 0x7fbd5f824000
mmap(0x7fbd5f995000, 458752, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x195000) = 0x7fbd5f995000
mmap(0x7fbd5fa05000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x204000) = 0x7fbd5fa05000
mmap(0x7fbd5fa0b000, 31600, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7fbd5fa0b000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fbd5fbea000
arch_prctl(ARCH_SET_FS, 0x7fbd5fbea740) = 0
set_tid_address(0x7fbd5fbead68)         = 10410
set_robust_list(0x7fbd5fbeaa20, 24)     = 0
rseq(0x7fbd5fbea6a0, 0x20, 0, 0x53053053) = 0
mprotect(0x7fbd5fa05000, 16384, PROT_READ) = 0
mprotect(0x55912fc19000, 4096, PROT_READ) = 0
mprotect(0x7fbd5fc64000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
getrandom("\x7a\xe4\xde\x15\x62\x4c\xb0\x94", 8, GRND_NONBLOCK) = 8
munmap(0x7fbd5fbef000, 212003)          = 0
fstat(1, {st_mode=S_IFCHR|0600, st_rdev=makedev(0x88, 0), ...}) = 0
brk(NULL)                               = 0x559138b51000
brk(0x559138b72000)                     = 0x559138b72000
write(1, "hello, world\n", 13)          = 13
write(1, "hello_libc_write: hello, world\n\0", 32) = 32
write(1, "hello_syscall: hello, world\n\0", 29) = 29
exit_group(0)                           = ?
+++ exited with 0 +++
