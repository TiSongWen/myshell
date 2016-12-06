#include "myshell.h"

const int max_name_len = 256;
const int max_path_len = 1024;

/**
 * 命令提示符：提示格式 用户名@主机名:路径$
 */
void typePrompt(void) {
    /*
       struct passwd {
            char * pw_name; //用户账号
            char * pw_passwd; //用户密码
            uid_t pw_uid; //用户识别码
            gid_t pw_gid; //组识别码
            char * pw_gecos; //用户全名
            char * pw_dir; //家目录
            char * pw_shell; //所使用的shell 路径
        };
     */
    struct passwd *pwd;
    char hostname[max_name_len];
    char pathname[max_path_len];

    pwd = getpwuid(getuid());
    gethostname(hostname, sizeof(hostname));
    getcwd(pathname, sizeof(pathname));

    printf("%s@%s:%s$", pwd->pw_name, hostname, pathname);
}
