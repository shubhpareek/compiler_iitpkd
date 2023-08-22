
struct varlis{char *nam;struct varlis * next;};
struct arglis{int typ;struct varlis* v;struct arglis * next;};
struct fdecl{char * nam; struct arglis * arglit;};
//struct vart{char *nam;};
struct arrtype{char *nam;int siz;};



struct glis{
int wh;
union{
	struct arrtype * at;
	struct fdecl * fu;
};
struct glis * nex;
};

struct gdec
{
int typ;
struct glis * val;
struct gdec * next;
};


typedef enum {ifelse,iff,whle,assstmt,writestmt,writeexp,varexa,exp} stmtp;
typedef enum {eqt,plus,minus,multiply,divide,rem,gt,lt,gte,lte,ee,nt,num} operat;

struct nptstmt{
	stmtp wt;
	struct nptstmt * ifst;
	struct nptlist * ifl;
	struct nptlist * elst;
	struct nptstmt * dost;
	struct nptstmt * asle;
		struct nptstmt *ex;
		struct varlis * vl;
		char * s;
		int num;
		operat op;
			struct nptstmt *exl;
				struct nptstmt *exr;
};

struct nptlist{
	struct nptstmt * val;
	struct nptlist * next;
};



