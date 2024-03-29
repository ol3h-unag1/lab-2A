#include <fstream>

#include <vector>
#include <string>

#include <filesystem>

#include <limits>

#include <chrono>
#include <ctime>

#include "Dictionary.hpp"
#include "ErrorMsg.hpp"

//std::vector< std::string > testWordsSource
//{
//    "vrmeeynvezvzkxfjdsyq",
//    "nirsankdhsazijoirety",
//    "uyfnaucmgcvofybnzhjj",
//    "yhzkiyhehrnfnpeyokgq",
//    "xvhangyfbmsomlquimmw",
//    "czaglmzpvpqzowgzajij",
//    "ukjgxgymqpldhjudzlie",
//    "jgvdtcdijyzjktavmrxi",
//    "vryakmucwceyfqfaigrg",
//    "bhxqcxkprlznddpxhqho",
//    "itydjknndddodwegwuvw",
//    "rpxurvvtqnpafftksuch",
//    "sqrjquufivtwomuigtvg",
//    "otmpdabincazbdhgstme",
//    "hcytimhnqhebyotwusfj",
//    "eshvpxaeckhlxwzlfhhl",
//    "aouiyjwuqljuuzuxjyjt",
//    "kvqequkkgcxccjegurzl",
//    "ymvpqvadhusxfaqdtkei",
//    "iepuookeiyigwnovdobd",
//    "lrcnabifiwcglbhazqac",
//    "tnrqoabaiybapmqifckr",
//    "gayzmyoyanxnfosdehgp",
//    "dmszqoeebaeadrkxuyiv",
//    "mbuazjnngtkdzbsnjjnb",
//    "tdzfvuzzkwljmybyivly",
//    "pnajzapjczauimqmbglo",
//    "meqmbmfmpmzcninhhbin",
//    "repvoqtusopohkvstssf",
//    "rhjlkmqidivnvvovgnib",
//    "umhxamdhtyrsqnwcbxoo",
//    "swsyompskrxiszwodrja",
//    "zfdbftlkakvnasufjfsq",
//    "dmvswswlbinniwnoxspu",
//    "dufjcfanjphhhrfisstt",
//    "zclwpsjdmhieqstiegwf",
//    "bmecxukzxhpcvfwvgthd",
//    "ufazjfkzpgbggntigqin",
//    "lofrutwsvhngdfbcvizb",
//    "xsgukuplcxjommbzgbxr",
//    "ysmwkhpgottlzkglwhzt",
//    "mjnjiaanrjpmmyjflevt",
//    "uipwrcweexunovygoqar",
//    "zhntzxnmsskdenoffxqa",
//    "ogsmiwyiwecgyhnlgrnq",
//    "fqndsilcoijmwgygiasr",
//    "oguqwbkqdzhvnrkjftdz",
//    "nliacbmoyqleiupmlspl",
//    "ozwpqbxvfcrshtzelhpv",
//    "rxvtbftewtnntrttwlef",
//    "ybfhsxjwhbfzyyshtecz",
//    "ssgfeioqhwdbqsisalba",
//    "twauzhsmhexkwyrgfgws",
//    "lfjwvjbczrxjekwcoeml",
//    "tezgcxjvpizndpcxqhrj",
//    "jnzbiwywkzlpcpjjbefx",
//    "nwavicupizatpndkqgpy",
//    "alvxemtxgfpjotslscpt",
//    "fvcbrcylxraiciamcxrj",
//    "oemdbjxavknuxiofdkix",
//    "tnlkjwtemkewntcrenal",
//    "zvlgftolinxpcmiuthoq",
//    "kgdxrkdijcwhepicdfma",
//    "bxwbtzgthlgnlucebnyk",
//    "pwnosmjttutprewdcsor",
//    "xspeltmlppwqbxibmmdj",
//    "gxcrkobbgpximvqpqwpb",
//    "izatfgmetounsnfddbyt",
//    "vpjdkocgeqmemrofeihs",
//    "piymrwbfezgbgkzpgcub",
//    "krjxovmzvchzgyzrrycv",
//    "wnehjfalgvhxjywblykv",
//    "qfezrpzyphvwmavvvika",
//    "flwccorzflbdqcyvghwf",
//    "hlfwrxccglgvegnxdhio",
//    "mntuhzbuowacrvxpldih",
//    "qzkrtdehdfewzdleddfz",
//    "bqvmnmeeakndvvjwwxrm",
//    "ehchkcxyaywuzapolcxd",
//    "wfhjusnmubuxhablpjkv",
//    "dtigbudosfgihbzlvlnj",
//    "hfkckjyhpikhlhtkwthf",
//    "stfsnlwiqqpdgcivdwpe",
//    "uafdczbqyrpaidvqqeur",
//    "sxweqqiywjhbhmjfifhb",
//    "kcaonnssnhhwbakvxncy",
//    "wjppudvwgrlygzeorgjs",
//    "pksvpsymnpnssumbwuut",
//    "cafpffnlfbnqlrznwjft",
//    "npenfywurzllyfptawrv",
//    "qpvkahcrfqqpphwbdthw",
//    "upaknlwjkhttbirvtzhb",
//    "brbdnsorqxgquqygfzpm",
//    "zvyrxqfawnedurnnlcka",
//    "wlxhivazdfephjewuhoy",
//    "obghsuxchstchtdhuxrl",
//    "mfxmtweqindeslorsqra",
//    "pdultvzzipajpfmnanqz",
//    "ifeaidfycnqsatdsmmky",
//    "kgyzcfmcgrzuowicqmeu",
//    "ervuiwxiemirajzhtmad",
//    "ezzokxfqgcnhzbmkjmxd",
//    "nlyprnnnwjkonwiqokoe",
//    "febofgaerligynbmyinb",
//    "rcrikhcwmzrvikzkupxg",
//    "akguzfalatbxbtzgojej",
//    "bqryoxjffeljlpfhlepz",
//    "dtwpgulihcrpmlsskbli",
//    "thewovcdnlotdwectado",
//    "xzsduqblwvghuuattjjs",
//    "nvtavmxmngucufwkijfe",
//    "bysnhdwkpttbgbjxxyuf",
//    "dcrzocapunabrewscdrx",
//    "hsowlrqrrcugzbfvojkr",
//    "udreucfjypbympirshrz",
//    "ifgpfelyrnvexzahmcud",
//    "hjenznitywklfxygagjr",
//    "xtxdclwmdfbsursqokmm",
//    "gxsogeuwblmxixjbhsri",
//    "ktjdlnwgeldjiutlmoox",
//    "gyeourffxzkoizbjgwer",
//    "ubredxyodmrvoglcnaev",
//    "lismtmlyoxrrwnpftrjr",
//    "ouznsiyldoheqdqrwgbs",
//    "kwhusjpjqzsnmsuqnabl",
//    "gxkakywkxmkhebilffcp",
//    "sxtfxrmvfjfqlfaeqryp",
//    "npjdjtktivwrjdntcsqb",
//    "xpfhftqmgqvwjekgimof",
//    "bmoetftpdxhbrmhabgep",
//    "mnrmywqsepfgyjcaizcl",
//    "uiqfeukmbqipklxjmkkg",
//    "bjumohbaszsynlqnjyya",
//    "ksdkjdpiextyksfcmill",
//    "wjwsbllekcxlxpdetkwx",
//    "bsjvgwnugdyfobfcvtdb",
//    "lehmjxxskoifthnjkoze",
//    "jshamlrkmmdygjcprsse",
//    "lsbdsncoxbgrbnrdsqqa",
//    "tcauzqxmrzdumwwypixp",
//    "ohxcoqugidubdnyetiwl",
//    "mcoyrlcbyuzmpgcsnrtg",
//    "qchlpcntoqlyictfrjml",
//    "xqgbddvwhpsmdectcpsd",
//    "ryumsfadgvcdzzmycfdm",
//    "hartrnhcrcupdkmwdobm",
//    "vfcpwpsasnrouwqicnog",
//    "bitccroryvqawaagszsl",
//    "sbrhihflwjfmsdgoeetq",
//    "absrzwlbdijjllppuvxl",
//    "pqldysemqisvhedgyypi",
//    "kgsfxupulttnqtinkudz",
//    "qgmcwovugnyrumvodzft",
//    "nidtivhfmygtnvzukihb",
//    "qbvlcgmxrilbeyjfywyc",
//    "qfnmseefyajpooodyypu",
//    "eprveffzuxifcjdgsuou",
//    "rbrnbdnghafmjhiwcjga",
//    "bvzbfbarnjumpqjdurui",
//    "rsqownagamosoqaxsmdf",
//    "evqurcpresqsnpjcvigg",
//    "yagpcnoxfihurhkqkglb",
//    "otehqgiexdfzsshmhtuu",
//    "oarsisqiesyjwcavqjor",
//    "ajbwttsayscorbpytfwo",
//    "utflamvsjpzhermhxiwb",
//    "hcujqslfgxvhoviutfre",
//    "nodauyjfqlzpzqwbjmzc",
//    "zcaauskrnstuliemcxvx",
//    "iwokekpgaaoaccbwyxsj",
//    "uswapboflotkmltkjdpw",
//    "yixkhzrzfawuntxilexl",
//    "hqfecyjbhdrbyfwhelpo",
//    "yhmpkootyxyaokopktum",
//    "pnuwjgrnyaielzugbfzp",
//    "valrefokxgzcrvcegjjb",
//    "fbslxfupfrubkahokife",
//    "dnuosflvqtdsziltrzaf",
//    "kcfwzrurwaqxdghnotjo",
//    "ztijzrzggwpxxmcerskz",
//    "mlpmpeorbsxllibmdlgm",
//    "ymcrnwsxrfwjkgkzyvbc",
//    "uswjasmtfhqsiythylso",
//    "coigfymvrwwkjxhvuzey",
//    "aynymsjpgfowdbdknbgm",
//    "ngygoaiapgcfotvxykom",
//    "xnfjgvxsobeuqzipmtql",
//    "jlcuqkyykydgmwavhipj",
//    "bogljfqtphfeqtpjypur",
//    "fmgufdrnajgitwvermtg",
//    "gcmvedccnenvmdgmtqmw",
//    "aicwmkwnezymluauopoo",
//    "pltmwnflmekzjjturkyo",
//    "seiumrsmychvbjuxkdow",
//    "hjkzcamxequwuqrsqeah",
//    "bjkcxrhhefukehlywzqf",
//    "ykejptmtvhzsxihxgnmq",
//    "sygybuesiczhynafjhcp",
//    "ehwazzvylnpymlvcyjkc",
//    "covsotmyxkpoykaixhnk",
//    "vkuntcriyntdqfmgrqkg",
//    "ydcdkwlcdevnljdgwasb",
//    "rnvtfraycafacaggakhw",
//    "ncqhuajhrnjztcycyftz",
//    "ilshmuiukfxehrmujvzj",
//    "drncgbszclzxiccghxoa",
//    "gcjgkrbnohcbikciaxwl",
//    "wjksbrhxytpdijqlxmcz",
//    "hozuqbwatuekpkegfima",
//    "ndncokfgdmxinaghejlr",
//    "xweiayzexqmzmqwdgeaw",
//    "uvrguezwodbqvtrfxark",
//    "gqzcmlxvwdfxrjvjnbki",
//    "ymkvfrfwjdolngolxcin",
//    "mpxwgemsbdcoexbkekcz",
//    "afvezalguuhdyblroxzd",
//    "wjyfaaizprbzkjzumlal",
//    "ttftailowixztseimlii",
//    "psvvksyazgnghcbuklot",
//    "xvhtvaexzrkqimhwbcjx",
//    "dvhbtfrgmdpeqimuqaui",
//    "tsunawlymggydqnmjaow",
//    "oogrggkaqbujhgogmvea",
//    "vczqibifowryebshghiq",
//    "cnwnvqeygbbptkdaljvp",
//    "kmjitnfwqspcyzeaunpe",
//    "wdigddxyyfgaekltdztk",
//    "tcfayokodxhqspqftcrc",
//    "rldufgcqmsywawgaihli",
//    "lxsdfesqqenzwehjrqzz",
//    "kozohacigfukhavvypir",
//    "jnvaqhaekmxxehpmprmk",
//    "rmohmdkyfkmjwzywrewb",
//    "ogymyscccnkdiebzsndo",
//    "ixmiiksvbeylhnqrhmiy",
//    "qovkluymdswsqwxmfkxk",
//    "futohvenbjzdvbjngkdi",
//    "egmcfntidkfqwwnlowdx",
//    "qqklmbdqaasubwkjjqec",
//    "apzqvqfjzfjidxtbnltd",
//    "vobsparitcbxakqxwiki",
//    "ghpmxgijehojrmnpodre",
//    "xielkoecijyhbyblxlsw",
//    "amxtaixqravyilemqeac",
//    "iiodqvdwiuqpikfnhavl",
//    "skgjdjjnqauxxjzfwhnq",
//    "vmagnujdwxnkpjmkcpmp",
//    "dblsiabuwtuyhyhbdblk",
//    "ycwtkanxcyjyfjocmojr",
//    "jvkheshoiiuoapewocam",
//    "zwmsqrxslhueybjnsjxm",
//    "szvnapfrpelcduaitdoy",
//    "ookwxhqxrosoujzlcobo",
//    "itegzxkdvnlbokwrfawe",
//    "bqjrfmqxnoqpbqdmcgqs",
//    "mvwhhbtvlgzyjmjimjmd",
//    "ctipdyvcrsibrqgmzlem",
//    "evteprtjbwdyxjdflaeb",
//    "biacmnzyatnmxoifzymh",
//    "drrzwhlaysamutyzldyq",
//    "lafuuprcpewqxbqloybv",
//    "ehvecqtbmjkpyqsdxdqi",
//    "dzkbhjxolwsqugelmcor",
//    "rjzderredckrqrmtptfu",
//    "nwyaqmyesdlbeniwwtok",
//    "wprmvogtkhqdxhfjsmda",
//    "londgrpzgusqtbyoygpm",
//    "mrqaoinayyfkbbozncav",
//    "eyqfncwsexvojynshotk",
//    "umibedihscsorwxdiido",
//    "rufzxcntikpzcswhkmxk",
//    "znoxmnyzxubmqkntlwgh",
//    "imdlmebnepxzrzmbgxkm",
//    "ekvwcgofegajyreshhxr",
//    "asfgqfuglegllvaqewog",
//    "xrobbbvxfjkwetyjsgro",
//    "olwuuqewepyvccjtdvrn",
//    "mjupipvckpjmvdtubvzn",
//    "mtlzicacectoxrozcfad",
//    "rkmkcpumodnmmsqtoctt",
//    "wfshryemtzuntdksvqmy",
//    "bbxanmzjxrdrpatkahds",
//    "bplomfjekrpxhezskzef",
//    "plcnowosicjpyggibhsi",
//    "qhfbtawcfxatipbuxbxh",
//    "rsrrcklaynkwbubizwjf",
//    "dflcukuffduwqcanyznk",
//    "kpbzxywuytqlutpgmzun",
//    "xjdwagsqbzkzuuocpthl",
//    "nopktvjsuaodpyhzftiw",
//    "hcihpovphliasmbxazgt",
//    "iysgpawwfojwtdohoncl",
//    "rpmrtvbsisxahygtqddq",
//    "npvmqyegqgjkbtyrkkrs",
//    "vshbalrjtarcswoesqai",
//    "wonnqwgsnvjqruukscvw",
//    "lrlwhbctjtetluuqrvxt",
//    "cnmrslwxvuocarsewwpy",
//    "iqcblqqtkraayxhqwnhc",
//    "akxedmjyzmiodjswxkxu",
//    "egcllpkwqrjknsnqgdad",
//    "sasnllwjpfdgbokvumqz",
//    "edvsdvvllzmxihaxigug",
//    "kwmvysvjsigjnojjfxfb",
//    "pywayqjitpnzbtyjrkyx",
//    "mduokcaspznkcetyvsih",
//    "ircisrpsqlrawnnfnnzm",
//    "qykpiffskfzixcokhver",
//    "evrfcpppivstfhvogbrn",
//    "xqudcrrlywtpizwhgytw",
//    "wftviufcrioefbtmfrbd",
//    "vbozqqrnjnoomwlxpvkt",
//    "klvuqywludsgwodmxikg",
//    "bdkthgsrmokfncubquhd",
//    "dswxxpifmcwhnyrehoqn",
//    "qlelhawvkzoerrkugoko",
//    "qqezjexmozaafkcdyakt",
//    "wlvrhvtoorkttvakgwcf",
//    "prtsehybhtetujxvedqf",
//    "oaxtwvgrellnxppgkmey",
//    "gizneabqyycswmlvrssd",
//    "bqzolkslqskhhhqacptl",
//    "klvzvvievlgdddlflfwb",
//    "qlsqjygtqhvvdesjeeld",
//    "bcrulgugwtzwukhzxior",
//    "knpcimfyolpkdariquvq",
//    "vapvrmkegppljhjmuhzi",
//    "wdiujqqwmtatrthlizgn",
//    "nmxcespebfccoocqgmpd",
//    "xhzfptdbqzpuerjiwtax",
//    "eudztxnarhwfmzemlwat",
//    "xvmuhcozxjdgtjujyjde",
//    "exfcmupckbjvxhjmnmfg",
//    "avbaonnkbomhjlryhsbn",
//    "btfkmkglzvyrvgxtqyip",
//    "qazncdpnilmdqotxchee",
//    "iueaprwflybxnsegsysh",
//    "mqhrchwlfhxbnlgiiitq",
//    "zrlcjmydfqgvalljceyz",
//    "dkaxrtigzyjqhmykoiny",
//    "nwidnzpldrkxdugmxxyb",
//    "enthioznoqmquhohesbl",
//    "bkpfdllwkqyypxgxmion",
//    "nedflomqbiqixtotpjsp",
//    "spemchevsdcpjnydxtmj",
//    "dewhmmkmjidkcoogmofj",
//    "jscvgkheruafnfkwigiu",
//    "hjixkebyqbzpudcfyekw",
//    "jaadbvdwotlsoghlignw",
//    "oqlncdghbanasezkliiw",
//    "vuwuoveccydmgeoreqmc",
//    "gtjpqrtgcuttcwodwwaf",
//    "nztpmhthjehotfcazttw",
//    "gtqcdqajcmmvcgtourap",
//    "ourznmeeqkakfycragbw",
//    "dnxxabsazutjrqevmtkz",
//    "amombytpnwjotcjnxjla",
//    "geoxvdxqiwckdztdwrav",
//    "idmtpyqnmtlxqmruujfk",
//    "aptqczvkdnmuxjgylsvt",
//    "cyvlzhphghgcijufmhju",
//    "ovmynckpihceuzmnacxp",
//    "iqbnhophrvtsrmpvnbpw",
//    "fcvoknbsumruarmiwise",
//    "wzgpmldqlcagtrdfkeas",
//    "wpzuxvbrltfqqqnyipjx",
//    "lkcrzxufnslmbctswzgr",
//    "arudolptruhroqkpcavb",
//    "hnnstrkeswofvdjoijgo",
//    "caxhnsznansmukinipxf",
//    "mpnyvytrgdpzzhftmnii",
//    "shdoqrewmjajeaixtfeb",
//    "ozhxtgvvhynbbwwujsah",
//    "xvwkbnypglvvvnufluix",
//    "ficogzhdrkzlrgxuwfgq",
//    "clklebuxrbvunvkajrlu",
//    "jtnurlgrgwmcwackccrp",
//    "aztvpcptupmucirvahex",
//    "scitbehapudvemtkiunv",
//    "ycmhcvvjdedjpyyzankz",
//    "ybpiomvkpppedihvdavs",
//    "gmmbdsvhghbsiidjdgib",
//    "vsqapxnbrjkxzekkxmgh",
//    "tkhlsutsoxbmsihyhaaq",
//    "ndivvtxdfjybvitedukk",
//    "ynrnelrxccznvcqkydou",
//    "zicptmfyvfgdhxokieab",
//    "zgpxpwfimltkxgsogmvz",
//    "tioawsdccqcgznhinrwr",
//    "amlxqkdzuclypgmpongb",
//    "aawnglgsrdwcbpvrfnlq",
//    "uzszglygoqouivsdgunt",
//    "mtpgohoiaqnacrdneioa",
//    "kshptyhqtrxxybwanlia",
//    "vfhzfuezpapkvlyqhwqg",
//    "mwbxcanvqqsjiqluhqfm",
//    "evnqyxodbgzjrmdyogrc",
//    "xyuyplgwwlvmakpfhkum",
//    "uafczzcsqmdgvzuzdrij",
//    "ehtahicezxnmkubplpnf",
//    "oehmzzpaiwexdcmajtdg",
//    "otcqyjdpsogqesgscnye",
//    "tygewzvziuudpqhmwvvb",
//    "atmohdzxhlwjzybxuqzr",
//    "guohqvoyefahdjsopanv",
//    "xayeeljcdmsjgzlsrghq",
//    "ahgctnzidsedpbvqxjnq",
//    "vuczwoqjpbjfsxypzbub",
//    "yjqcvccqoheerdjbhbog",
//    "jiuoluvdkvmjsliwxpdz",
//    "kpcrisqmswadscaahadc",
//    "ezfxfbqvtvtcjprogqiv",
//    "zxvtihfqtvaeixemlpiy",
//    "hjhsnebojsvzwibjkieu",
//    "xellagczhaimvnojpgkc",
//    "birxisledsytkdhogoeb",
//    "cbhkcdoeobkzzsrfjkln",
//    "ocqhbbnkcyeplyxrlkjq",
//    "soyieyvcfrawfivecfib",
//    "wqyilosanugsxhpwivep",
//    "rcqucszajpftvopntpgh",
//    "bfwymwxcpboagzxhkdvv",
//    "xeqdkmxcfulkymrqhyyl",
//    "kalwuojvqigdiggluljq",
//    "phsuannsrcgyzqeegqfs",
//    "uduoluibvsvugmvmdcjc",
//    "vqouorsejhxjecozasxt",
//    "izpodyjqppsvhnngoipf",
//    "faonlfiocazwfnzltiba",
//    "ldtjpbromxjsvjrcucot",
//    "xyedwtekivhnvwxwddhz",
//    "llmtndbenouvoznjggdc",
//    "fuibuhnirwkteatavsma",
//    "xgodiomkhabjlrnszzhe",
//    "yftwlyfkqjftwgcytrgc",
//    "yfevltidsmiyoknupgpg",
//    "cdypnmxltbeycjsmkwxz",
//    "ypuzlfxnhcdggohncupm",
//    "lydbwfevyvxtsvhxlxws",
//    "sthxvdipnqbdmeeeyhly",
//    "dskllatripvtognfxece",
//    "rztsumylyupaupidmjkd",
//    "jiaagjytoxpacttntgvg",
//    "mmslcutotrlwfvhsqvmw",
//    "biebmtzfxiwtwwwhqbnq",
//    "plmtfnqdpztmlwgszgic",
//    "homuhjmdiokslvgipuke",
//    "psiaumvqimjhrxiacsdk",
//    "jneamzbqsungnlplamoz",
//    "sghvnboclsvbbtwwfzmc",
//    "lqkmkqgzpkvnzvatzfkw",
//    "tpstkazgkxwgxptrrxkz",
//    "skbrwhqscnndaniwnxuv",
//    "dndgzqqdgdknzdylrrig",
//    "lgnfdecupremtnivnlqu",
//    "vgvqymswayxkufxxjsqx",
//    "impgzmndezvhhferuwet",
//    "nhfokhxnigecrkmscgsn",
//    "nrezinfrrqdnwvrumkzb",
//    "hanfkecvgmwnnophalvg",
//    "xjchdehvzuztoyqllvhp",
//    "ocujreroggsefshammer",
//    "uwkvbltjznejwtvsumgq",
//    "cvxlfqnbwlticaujxhcm",
//    "eysxnzooyfystisadzgs",
//    "cojrkagmatngfogkyjyt",
//    "rsjzongznwofawcoxvxa",
//    "afdnlsctsyhdqosrxaju",
//    "kkloxytdpqiifqahanpa",
//    "uvouxprfctljvebfiieg",
//    "oybhnufmjkezdybreqdb",
//    "pxlzdicqvgizervfypvv",
//    "elabdmcspylvaejejaql",
//    "yzpgbgvcbjvkxomxqgtq",
//    "vszuogmxjsrxhtyyhpjp",
//    "ojjklqltfenbxspxdrlc",
//    "kxybqcgrshcbudpbqrrg",
//    "ugmfssffbusfygidbgli",
//    "idzkpvxzvszgpgvqgtrd",
//    "xhejvidlozlhllreneis",
//    "zvlczbswupfjnjmnfvni",
//    "oiybfpknvqcwauqevrhm",
//    "gwupqamzpmzaxeunspqr",
//    "vuhlscmgavppucxjfbjt",
//    "tjkmfjqzxmfnetttolfs",
//    "lpisnaxeunpghirwocej",
//    "xbycejzliuuhdegdkssf",
//    "nuskmxvxuhmukhwkmiow",
//    "equlbhbuxtmtzmsamgzu",
//    "waqxbzxnztgynkbfvmst",
//    "utjnubrspncskzqispgb",
//    "upqzzgzddcsamilizhsk",
//    "btkoxatrdufrpxdtdjzz",
//    "iuhvzchncsnbholfzruw",
//    "ubfaqeezmmdqddzbiyxq",
//    "qiouozbnfhbyhfmwisby",
//    "wbwrtzydzrjfwbbdmkxx",
//    "korozatsibxczrpjbwjb",
//    "kiuhmrgjxnqxxxvsdgys",
//    "nqmypwmxcsgmmzuultss",
//    "zdvtssjazqyhhyjcjyjj",
//    "gjnvgjiuwnteuqatqnky",
//    "bustxdfddedoedsesxdl",
//    "cemfjxjnfkaomwcvzbkg",
//    "mcbwpjxgbwczxpruhdls",
//    "mxynnbwqdfgxwhliyvar",
//    "eaymjxdackshxozhqtza",
//    "cpcbhgovotxqnecopusk",
//    "jqcscihxfzveplolmzjq",
//    "ytdqmgkdonqyolqmqlnk",
//    "esgxxrvxfnjxmpztdefs",
//    "avnsrntquqygvewhyezx" 
//};
    
bool Dictionary::Init()
{
    return ReadLibrary();
}

std::vector< Word* > Dictionary::GetExersizePortion()
{
    static std::size_t totalIndex = 0;
   
    std::vector< Word* > portion;
    for( std::size_t i = 0; ( i < _portionSize ) && ( totalIndex < _words.size() ); ++i, ++totalIndex )
    {
        portion.push_back( std::addressof( _words[ totalIndex ] ) );
    }

    if( totalIndex >= _words.size() )
    {
        totalIndex = 0;
        _words.clear();
        ReadLibrary();
        return GetExersizePortion();
    }

    return portion;
}

std::string GetUniqueStamp() 
{
    static std::size_t counter = 0u;

    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto seconds = std::chrono::duration_cast< std::chrono::seconds >( duration ).count();
    return std::to_string( seconds ) + "_" + std::to_string(++counter);
}

void Dictionary::UpdateLibrary()
{
    if( _words.empty() )
    {
        PRNT_ERR( "Can't update library: no words to write!" );
        return;
    }

    auto const p = std::filesystem::current_path();
    std::filesystem::rename( p / libraryFileName, p / ( GetUniqueStamp() + libraryFileName ) );

    std::ofstream ofs{ libraryFileName };
    for( std::size_t i = 0; i < _words.size() - 1; ++i )
    {
        ofs << _words[ i ] << std::endl;
    }
    
    ofs << _words.back();
}

double ClapRating( double rating )
{
    double const lowest = 0.0;
    double const highest = 10.0;

    if( rating < lowest )
    {
        return lowest;
    }

    if( rating > highest )
    {
        return highest;
    }

    return rating;
}

bool AreSame( double a, double b )
{
    return std::fabs( a - b ) < std::numeric_limits<double>::epsilon();
}

bool SortWordsByRatingThenAlpha( Word const& left, Word const& right )
{
    if( AreSame( left.GetRating(), right.GetRating() ) )
    {
        return left.GetStr() < right.GetStr();
    }

    return left.GetRating() > right.GetRating();
}


bool Dictionary::ReadLibrary()
{
    std::ifstream libraryFileInput{ libraryFileName };
    if( libraryFileInput.is_open() == false )
    {
        PRNT_ERR( "CAN'T OPEN LIBRARY FILE: " + libraryFileName );
        return false;
    }

    while( libraryFileInput && !libraryFileInput.eof() )
    {
        double rating;
        libraryFileInput >> rating;
        rating = ClapRating( rating );
        if( !libraryFileInput.eof() && !libraryFileInput.good() )
        {
            PRNT_ERR( "Error reading rating at line: " + std::to_string( _words.size() ) );
            _words.clear();
            return false;
        }

        while( std::isspace( libraryFileInput.peek() ) && libraryFileInput.seekg( std::size_t( libraryFileInput.tellg() ) + 1 ) );

        std::string wordStr;
        std::getline( libraryFileInput, wordStr );
        if( !libraryFileInput.eof() && !libraryFileInput.good() )
        {
            PRNT_ERR( "Error reading word string at line: " + std::to_string( _words.size() ) );
            _words.clear();
            return false;
        }

        while( wordStr.size() && std::isspace( wordStr.back() ) )
        {
            wordStr.pop_back();
        }

        _words.emplace_back( Word{ wordStr, rating } );
    }

    std::sort( std::begin( _words ), std::end( _words ), SortWordsByRatingThenAlpha );

    //std::cout << "Library: " << std::endl;
    //for( auto& w : _words )
    //{
    //    std::cout << w << std::endl;
    //}

    return true;
}

//bool Dictionary::ReadLibraryTest()
//{
//    _words.reserve( testWordsSource.size() );
//    for( std::size_t i = 0; i < testWordsSource.size(); ++i )
//    {
//        testWordsSource[ i ] = std::to_string( i ) + testWordsSource[ i ];
//        _words.emplace_back( Word( testWordsSource[ i ], static_cast< double >( i % 10 ) ) );
//    }
//
//    return true;
//}
