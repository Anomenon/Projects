#include <iostream>
#include <vector>
#include <random>
using namespace std;

struct Kanji{
    string kanji;
    bool was_shown;

    Kanji(string k, bool s) : kanji{k}, was_shown{s} {}
};

const int Overall_size = 394;
Kanji kanji[Overall_size] = {{"一", false}, {"二", false}, {"三", false}, {"四", false}, {"五", false}, {"六", false}, {"七", false}, {"八", false}, {"九", false}, {"十", false}, {"百", false}, {"千", false}, {"万", false}, {"円", false}, {"日", false}, {"週", false}, {"月", false}, {"年", false}, {"時", false}, {"間", false}, {"分", false}, {"午", false}, {"前", false}, {"後", false}, {"今", false}, {"先", false}, {"来", false}, {"半", false}, {"毎", false}, {"何", false}, {"人", false}, {"男", false}, {"女", false}, {"子", false}, {"母", false}, {"父", false}, {"友", false}, {"火", false}, {"水", false}, {"木", false}, {"土", false}, {"金", false}, {"本", false}, {"川", false}, {"花", false}, {"気", false}, {"生", false}, {"魚", false}, {"天", false}, {"空", false}, {"山", false}, {"雨", false}, {"電", false}, {"車", false}, {"語", false}, {"耳", false}, {"手", false}, {"足", false}, {"目", false}, {"口", false}, {"名", false}, {"店", false}, {"駅", false}, {"道", false}, {"社", false}, {"国", false}, {"外", false}, {"学", false}, {"校", false}, {"上", false}, {"下", false}, {"中", false}, {"北", false}, {"東", false}, {"南", false}, {"西", false}, {"右", false}, {"左", false}, {"字", false}, {"見", false}, {"聞", false}, {"書", false}, {"読", false}, {"話", false}, {"買", false}, {"行", false}, {"出", false}, {"入", false}, {"休", false}, {"食", false}, {"飲", false}, {"言", false}, {"立", false}, {"会", false}, {"多", false}, {"少", false}, {"古", false}, {"新", false}, {"大", false}, {"小", false}, {"安", false}, {"高", false}, {"長", false}, {"白", false}, {"私", false}, {"竜", false}, {"秒", false}, {"文", false}, {"化", false}, {"森", false}, {"守", false}, {"田", false}, {"世", false}, {"死", false}, {"始", false}, {"待", false}, {"者", false}, {"漢", false}, {"曜", false}, {"英", false}, {"力", false}, {"音", false}, {"犬", false}, {"方", false}, {"地", false}, {"京", false}, {"用", false}, {"家", false}, {"画", false}, {"海", false}, {"黒", false}, {"春", false}, {"秋", false}, {"夏", false}, {"冬", false}, {"昼", false}, {"茶", false}, {"走", false}, {"色", false}, {"弟", false}, {"兄", false}, {"妹", false}, {"姉", false}, {"愛", false}, {"好", false}, {"氷", false}, {"了", false}, {"体", false}, {"丈", false}, {"夫", false}, {"毛", false}, {"持", false}, {"当", false}, {"穴", false}, {"良", false}, {"不", false}, {"児", false}, {"止", false}, {"心", false}, {"々", false}, {"仁", false}, {"回", false}, {"運", false}, {"同", false}, {"可", false}, {"彼", false}, {"閉", false}, {"許", false}, {"注", false}, {"全", false}, {"合", false}, {"明", false}, {"専", false}, {"伝", false}, {"声", false}, {"次", false}, {"祖", false}, {"記", false}, {"事", false}, {"青", false}, {"緑", false}, {"黄", false}, {"赤", false}, {"紫", false}, {"之", false}, {"工", false}, {"貴", false}, {"保", false}, {"護", false}, {"正", false}, {"元", false}, {"次", false}, {"番", false}, {"常", false}, {"宮", false}, {"村", false}, {"禁", false}, {"石", false}, {"互", false}, {"俺", false}, {"連", false}, {"泣", false}, {"猫", false}, {"鳥", false}, {"酉", false}, {"自", false}, {"晩", false}, {"内", false}, {"覚", false}, {"太", false}, {"固", false}, {"久", false}, {"波", false}, {"娘", false}, {"息", false}, {"夜", false}, {"狭", false}, {"苦", false}, {"早", false}, {"遅", false}, {"法", false}, {"住", false}, {"主", false}, {"凄", false}, {"妻", false}, {"稲", false}, {"任", false}, {"楽", false}, {"難", false}, {"差", false}, {"玉", false}, {"卵", false}, {"抜", false}, {"腰", false}, {"霧", false}, {"影", false}, {"島", false}, {"根", false}, {"屋", false}, {"族", false}, {"草", false}, {"竹", false}, {"性", false}, {"格", false}, {"的", false}, {"具", false}, {"資", false}, {"際", false}, {"実", false}, {"施", false}, {"布", false}, {"共", false}, {"有", false}, {"貼", false}, {"得", false}, {"意", false}, {"振", false}, {"込", false}, {"返", false}, {"使", false}, {"館", false}, {"図", false}, {"構", false}, {"管", false}, {"理", false}, {"総", false}, {"選", false}, {"予", false}, {"防", false}, {"定", false}, {"舌", false}, {"平", false}, {"辞", false}, {"典", false}, {"係", false}, {"数", false}, {"最", false}, {"初", false}, {"触", false}, {"媒", false}, {"受", false}, {"取", false}, {"変", false}, {"開", false}, {"平", false}, {"曲", false}, {"線", false}, {"王", false}, {"員", false}, {"弁", false}, {"士", false}, {"顔", false}, {"面", false}, {"池", false}, {"沼", false}, {"択", false}, {"町", false}, {"雪", false}, {"貝", false}, {"糸", false}, {"虫", false}, {"林", false}, {"場", false}, {"米", false}, {"通", false}, {"首", false}, {"作", false}, {"強", false}, {"市", false}, {"公", false}, {"野", false}, {"思", false}, {"点", false}, {"活", false}, {"原", false}, {"交", false}, {"近", false}, {"考", false}, {"売", false}, {"組", false}, {"知", false}, {"引", false}, {"計", false}, {"直", false}, {"朝", false}, {"台", false}, {"広", false}, {"夕", false}, {"教", false}, {"切", false}, {"算", false}, {"親", false}, {"形", false}, {"頭", false}, {"門", false}, {"答", false}, {"帰", false}, {"谷", false}, {"歌", false}, {"光", false}, {"科", false}, {"細", false}, {"丸", false}, {"室", false}, {"歩", false}, {"風", false}, {"紙", false}, {"戸", false}, {"園", false}, {"料", false}, {"無", false}, {"第", false}, {"界", false}, {"歳", false}, {"君", false}, {"冒", false}, {"転", false}, {"際", false}, {"達", false}, {"魔", false}, {"異", false}, {"映", false}, {"勉", false}, {"起", false}, {"寝", false}, {"然", false}, {"飯", false}, {"末", false}, {"単", false}, {"身", false}, {"問", false}, {"角", false}, {"沼", false}, {"美", false}, {"短", false}, {"軽", false}, {"羽", false}, {"船", false}, {"笑", false}, {"岩", false}, {"雲", false}, {"鳴", false}, {"弓", false}, {"港", false}, {"階", false}, {"路", false}, {"悪", false}, {"他", false}, {"橋", false}, {"岸", false}, {"客", false}, {"登", false}, {"速", false}, {"央", false}};
const string readings[Overall_size] = {"イチ・イツ・ひと~・ひと.つ", "ニ・ジ・ふた・ふた.つ・ふたたび", "サン・ゾウ・み・み.つ・みっ.つ", "シ・よ・よ.つ・よっ.つ・よん", "ゴ・いつ・いつ.つ", "ロク・リク・む・む.つ・むっ.つ・むい", "シチ・なな・なな.つ・なの", "ハチ・や・や.つ・やっ.つ・よう", "キュウ・ク・ここの・ここの.つ", "ジュウ・ジッ・ジュッ・とお・と", "ヒャク・ビャク・もも", "セン・ち", "マン・バン・よろず", "エン・まる.い・まる・まど・まど.か・まろ.やか", "ニチ・ジツ・ひ・~び・~か", "シュウ", "ゲツ・ガツ・つき", "ネン・とし", "ジ・とき・~どき", "カン・ケン・あいだ・ま・あい", "ブン・フン・ブ・わ.ける・わ.け・わ.かれる・わ.かる・わ.かつ", "ゴ・うま", "ゼン・まえ・~まえ", "ゴ・コウ・のち・うし.ろ・うしろ・あと・おく.れる", "コン・キン・いま", "セン・さき・ま.ず", "ライ・タイ・く.る・きた.る・きた.す・き.たす・き.たる・き・こ", "ハン・なか.ば", "マイ・ごと・~ごと.に", "カ・なに・なん・なに~・なん~", "ジン・ニン・ひと・~り・~と", "ダン・ナン・おとこ・お", "ジョ・ニョ・ニョウ・おんな・め", "シ・ス・ツ・こ・~こ・ね", "ボ・はは・も", "フ・ちち", "ユウ・とも", "カ・ひ・~び・ほ~", "スイ・みず・みず~", "ボク・モク・き・こ~", "ド・ト・つち", "キン・コン・ゴン・かね・かな~・~がね", "ホン・もと", "セン・かわ", "カ・ケ・はな", "キ・ケ・いき", "セイ・ショウ・い.きる・い.かす・い.ける・う.まれる・うま.れる・う.まれ・うまれ・う.む・お.う・は.える・は.やす・き・なま・なま~・な.る・な.す・む.す・~う", "ギョ・うお・さかな・~ざかな", "テン・あまつ・あめ・あま~", "クウ・そら・あ.く・あ.き・あ.ける・から・す.く・す.かす・むな.しい", "サン・セン・やま", "ウ・あめ・あま~・~さめ", "デン", "シャ・くるま", "ゴ・かた.る・かた.らう", "ジ・みみ", "シュ・ズ・て・て~・~て・た~", "ソク・あし・た.りる・た.る・た.す", "モク・ボク・め・~め・ま~", "コウ・ク・くち", "メイ・ミョウ・な・~な", "テン・みせ・たな", "エキ", "ドウ・トウ・みち・いう", "シャ・やしろ", "コク・くに", "ガイ・ゲ・そと・ほか・はず.す・はず.れる・と~", "ガク・まな.ぶ", "コウ・キョウ", "ジョウ・ショウ・シャン・うえ・~うえ・うわ~・かみ・あ.げる・~あ.げる・あ.がる・~あ.がる・あ.がり・~あ.がり・のぼ.る・のぼ.り・のぼ.せる・のぼ.す・たてまつ.る", "カ・ゲ・した・しも・もと・さ.げる・さ.がる・くだ.る・くだ.り・くだ.す・~くだ.す・くだ.さる・お.ろす・お.りる", "チュウ・なか・うち・あた.る", "ホク・きた", "トウ・ひがし", "ナン・ナ・みなみ", "セイ・サイ・ス・にし", "ウ・ユウ・みぎ", "サ・シャ・ひだり", "ジ・あざ・あざな・~な", "ケン・み.る・み.える・み.せる", "ブン・モン・き.く・き.こえる", "ショ・か.く・~が.き・~がき", "ドク・トク・トウ・よ.む・~よ.み", "ワ・はな.す・はなし", "バイ・か.う", "コウ・ギョウ・アン・い.く・ゆ.く・~ゆ.き・~ゆき・~い.き・~いき・おこな.う・おこ.なう", "シュツ・スイ・で.る・~で・だ.す・~だ.す・い.でる・い.だす", "ニュウ・ジュ・い.る・~い.る・~い.り・い.れる・~い.れ・はい.る", "キュウ・やす.む・やす.まる・やす.める", "ショク・ジキ・く.う・く.らう・た.べる・は.む", "イン・オン・の.む・~の.み", "ゲン・ゴン・い.う・こと", "リツ・リュウ・リットル・た.つ・~た.つ・た.ち~・た.てる・~た.てる・た.て~・たて~・~た.て・~だ.て・~だ.てる", "カイ・エ・あ.う・あ.わせる・あつ.まる", "タ・おお.い・まさ.に・まさ.る", "ショウ・すく.ない・すこ.し", "コ・ふる.い・ふる~・~ふる.す", "シン・あたら.しい・あら.た・あら~・にい~", "ダイ・タイ・おお~・おお.きい・~おお.いに", "ショウ・ちい.さい・こ~・お~・さ~", "アン・やす.い・やす.まる・やす・やす.らか", "コウ・たか.い・たか・~だか・たか.まる・たか.める", "チョウ・なが.い・おさ", "ハク・ビャク・しろ・しら~・しろ.い", "シ・わたくし・わたし", "リュウ・リョウ・ロウ・たつ・いせ", "ビョウ", "ブン・モン・ふみ・あや", "カ・ケ・ば.ける・ば.かす・ふ.ける・け.する", "シン・もり", "シュ・ス・まも.る・まも.り・もり・~もり・かみ", "デン・た", "セイ・セ・ソウ・よ", "シ・し.ぬ・し.に~", "シ・はじ.める・~はじ.める・はじ.まる", "タイ・ま.つ・~ま.ち", "シャ・もの", "カン", "ヨウ", "エイ・はなぶさ", "リョク・リキ・リイ・ちから", "オン・イン・~ノン・おと・ね", "ケン・いぬ・いぬ~", "ホウ・かた・~かた・~がた", "チ・ジ", "キョウ・ケイ・キン・みやこ", "ヨウ・もち.いる", "カ・ケ・いえ・や・うち", "ガ・カク・エ・カイ・えが.く・かく.する・かぎ.る・はかりごと・はか.る", "カイ・うみ", "コク・くろ・くろ.ずむ・くろ.い", "シュン・はる", "シュウ・あき・とき", "カ・ガ・ゲ・なつ", "トウ・ふゆ", "チュウ・ひる", "チャ・サ", "ソウ・はし.る", "ショク・シキ・いろ", "テイ・ダイ・デ・おとうと", "ケイ・キョウ・あに", "マイ・いもうと", "シ・あね・はは", "アイ・いと.しい・かな.しい・め.でる・お.しむ・まな", "コウ・この.む・す.く・よ.い・い.い", "ヒョウ・こおり・ひ・こお.る", "リョウ", "タイ・テイ・からだ・かたち", "ジョウ・たけ・だけ", "フ・フウ・ブ・おっと・それ", "モウ・け", "ジ・も.つ・~も.ち・も.てる", "トウ・あ.たる・あ.たり・あ.てる・あ.て・まさ.に・まさ.にべし", "ケツ・あな", "リョウ・よ.い・~よ.い・い.い・~い.い", "フ・ブ", "ジ・ニ・ゲイ・こ・~こ・~っこ", "シ・と.まる・~ど.まり・と.める・~と.める・~ど.め・とど.める・とど.め・とど.まる・や.める・や.む・~や.む・よ.す・~さ.す・~さ.し", "シン・こころ・~ごころ", "のま", "ジン・ニ・ニン", "カイ・エ・まわ.る・~まわ.る・~まわ.り・まわ.す・~まわ.す・まわ.し~・~まわ.し・もとお.る・か.える", "ウン・はこ.ぶ", "ドウ・おな.じ", "カ・コク・~べ.き・~べ.し", "ヒ・かれ・かの・か.の", "ヘイ・と.じる・と.ざす・し.める・し.まる・た.てる", "キョ・ゆる.す・もと", "チュウ・そそ.ぐ・さ.す・つ.ぐ", "ゼン・まった.く・すべ.て", "ゴウ・ガッ・カッ・あ.う・~あ.う・あ.い・あい~・~あ.い・~あい・あ.わす・あ.わせる・~あ.わせる", "メイ・ミョウ・ミン・あ.かり・あか.るい・あか.るむ・あか.らむ・あき.らか・あ.ける・~あ.け・あ.く・あ.くる・あ.かす", "セン・もっぱ.ら", "デン・テン・つた.わる・つた.える・つた.う・つだ.う・~づた.い・つて", "セイ・ショウ・こえ・こわ~", "ジ・シ・つ.ぐ・つぎ", "ソ", "キ・しる.す", "ジ・ズ・こと・つか.う・つか.える", "セイ・ショウ・あお・あお~・あお.い", "リョク・ロク・みどり", "コウ・オウ・き・こ~", "セキ・シャク・あか・あか~・あか.い・あか.らむ・あか.らめる", "シ・むらさき", "シ・の・これ・ゆく・この", "コウ・ク・グ", "キ・たっと.い・とうと.い・たっと.ぶ・とうと.ぶ", "ホ・ホウ・たも.つ", "ゴ・まも.る", "セイ・ショウ・ただ.しい・ただ.す・まさ・まさ.に", "ゲン・ガン・もと", "ジ・シ・つ.ぐ・つぎ", "バン・つが.い", "ジョウ・つね・とこ~", "キュウ・グウ・ク・クウ・みや", "ソン・むら", "キン", "セキ・シャク・コク・いし", "ゴ・たが.い・かたみ.に", "エン・おれ・われ", "レン・つら.なる・つら.ねる・つ.れる・~づ.れ", "キュウ・な.く", "ビョウ・ねこ", "チョウ・とり", "ユウ・とり", "ジ・シ・みずか.ら・おの.ずから・おの.ずと", "バン", "ナイ・ダイ・うち", "カク・おぼ.える・さ.ます・さ.める・さと.る", "タイ・タ・ふと.い・ふと.る", "コ・かた.める・かた.まる・かた.まり・かた.い", "キュウ・ク・ひさ.しい", "ハ・なみ", "ジョウ・むすめ・こ", "ソク・いき", "ヤ・よ・よる", "キョウ・コウ・せま.い・せば.める・せば.まる・さ", "ク・くる.しい・~ぐる.しい・くる.しむ・くる.しめる・にが.い・にが.る", "ソウ・サッ・はや.い・はや・はや~・はや.まる・はや.める・さ~", "チ・おく.れる・おく.らす・おそ.い", "ホウ・ハッ・ホッ・フラン・のり", "ジュウ・ヂュウ・チュウ・す.む・す.まう・~ず.まい", "シュ・ス・シュウ・ぬし・おも・あるじ", "セイ・サイ・さむ.い・すご.い・すさ.まじい", "サイ・つま", "トウ・テ・いね・いな~", "ニン・まか.せる・まか.す", "ガク・ラク・ゴウ・たの.しい・たの.しむ・この.む", "ナン・かた.い・~がた.い・むずか.しい・むづか.しい・むつか.しい・~にく.い", "サ・さ.す・さ.し", "ギョク・たま・たま~・~だま", "ラン・たまご", "バツ・ハツ・ハイ・ぬ.く・~ぬ.く・ぬ.き・ぬ.ける・ぬ.かす・ぬ.かる", "ヨウ・こし", "ム・ボウ・ブ・きり", "エイ・かげ", "トウ・しま", "コン・ね・~ね", "オク・や", "ゾク", "ソウ・くさ・くさ~・~ぐさ", "チク・たけ", "セイ・ショウ・さが", "カク・コウ・キャク・ゴウ", "テキ・まと", "グ・そな.える・つぶさ.に", "シ", "サイ・きわ・~ぎわ", "ジツ・シツ・み・みの.る・まこと・みの・みち.る", "シ・セ・ほどこ.す", "フ・ぬの", "キョウ・とも・とも.に・~ども", "ユウ・ウ・あ.る", "テン・チョウ・は.る・つ.く", "トク・え.る・う.る", "イ", "シン・ふ.る・ぶ.る・ふ.り・~ぶ.り・ふ.るう", "~こ.む・こ.む・こ.み・~こ.み・こ.める", "ヘン・かえ.す・~かえ.す・かえ.る・~かえ.る", "シ・つか.う・つか.い・~つか.い・~づか.い", "カン・やかた・たて", "ズ・ト・え・はか.る", "コウ・かま.える・かま.う", "カン・くだ", "リ・ことわり", "ソウ・す.べて・すべ.て・ふさ", "セン・えら.ぶ", "ヨ・シャ・あらかじ.め", "ボウ・ふせ.ぐ", "テイ・ジョウ・さだ.める・さだ.まる・さだ.か", "ゼツ・した", "ヘイ・ビョウ・ヒョウ・たい.ら・~だいら・ひら・ひら~", "ジ・や.める・いな.む", "テン・デン", "ケイ・かか.る・かかり・~がかり・かか.わる", "スウ・ス・サク・ソク・シュ・かず・かぞ.える・しばしば・せ.める・わずらわ.しい", "サイ・シュ・もっと.も・つま", "ショ・はじ.め・はじ.めて・はつ・はつ~・うい~・~そ.める・~ぞ.め", "ショク・ふ.れる・さわ.る・さわ", "バイ・なこうど", "ジュ・う.ける・~う.け・う.かる", "シュ・と.る・と.り・と.り~・とり・~ど.り", "ヘン・か.わる・か.わり・か.える", "カイ・ひら.く・ひら.き・~びら.き・ひら.ける・あ.く・あ.ける", "ヘイ・ビョウ・ヒョウ・たい.ら・~だいら・ひら・ひら~", "キョク・ま.がる・ま.げる・くま", "セン・すじ", "オウ・~ノウ", "イン", "ベン・ヘン・かんむり・わきま.える・わ.ける・はなびら・あらそ.う", "シ・さむらい", "ガン・かお", "メン・ベン・おも・おもて・つら", "チ・いけ", "ショウ・ぬま", "タク・えら.ぶ", "チョウ・まち", "セツ・ゆき", "バイ・かい", "シ・いと", "チュウ・キ・むし", "リン・はやし", "ジョウ・チョウ・ば", "ベイ・マイ・メエトル・こめ・よね", "ツウ・ツ・とお.る・とお.り・~とお.り・~どお.り・とお.す・とお.し・~どお.し・かよ.う", "シュ・くび", "サク・サ・つく.る・つく.り・~づく.り", "キョウ・ゴウ・つよ.い・つよ.まる・つよ.める・し.いる・こわ.い", "シ・いち", "コウ・ク・おおやけ", "ヤ・ショ・の・の~", "シ・おも.う・おもえら.く・おぼ.す", "テン・つ.ける・つ.く・た.てる・さ.す・とぼ.す・とも.す・ぼち", "カツ・い.きる・い.かす・い.ける", "ゲン・はら", "コウ・まじ.わる・まじ.える・ま.じる・まじ.る・ま.ざる・ま.ぜる・~か.う・か.わす・かわ.す・こもごも", "キン・コン・ちか.い", "コウ・かんが.える・かんが.え", "バイ・う.る・う.れる", "ソ・く.む・くみ・~ぐみ", "チ・し.る・し.らせる", "イン・ひ.く・ひ.き・ひ.き~・~び.き・ひ.ける", "ケイ・はか.る・はか.らう", "チョク・ジキ・ジカ・ただ.ちに・なお.す・~なお.す・なお.る・なお.き・す.ぐ", "チョウ・あさ", "ダイ・タイ・うてな・われ・つかさ", "コウ・ひろ.い・ひろ.まる・ひろ.める・ひろ.がる・ひろ.げる", "セキ・ゆう", "キョウ・おし.える・おそ.わる", "セツ・サイ・き.る・~き.る・き.り・~き.り・~ぎ.り・き.れる・~き.れる・き.れ・~き.れ・~ぎ.れ", "サン・そろ", "シン・おや・おや~・した.しい・した.しむ", "ケイ・ギョウ・かた・~がた・かたち・なり", "トウ・ズ・ト・あたま・かしら・~がしら・かぶり", "モン・かど・と", "トウ・こた.える・こた.え", "キ・かえ.る・かえ.す・おく.る・とつ.ぐ", "コク・たに・きわ.まる", "カ・うた・うた.う", "コウ・ひか.る・ひかり", "カ", "サイ・ほそ.い・ほそ.る・こま.か・こま.かい", "ガン・まる・まる.める・まる.い", "シツ・むろ", "ホ・ブ・フ・ある.く・あゆ.む", "フウ・フ・かぜ・かざ~・~かぜ", "シ・かみ", "コ・と", "エン・その", "リョウ", "ム・ブ・な.い", "ダイ・テイ", "カイ", "サイ・セイ・とし・とせ・よわい", "クン・きみ・~ぎみ", "ボウ・おか.す", "テン・ころ.がる・ころ.げる・ころ.がす・ころ.ぶ・まろ.ぶ・うたた・うつ.る・くる.めく", "サイ・きわ・~ぎわ", "タツ・ダ・~たち", "マ", "イ・こと・こと.なる・け", "エイ・うつ.る・うつ.す・は.える・~ば.え", "ベン・つと.める", "キ・お.きる・お.こる・お.こす・おこ.す・た.つ", "シン・ね.る・ね.かす・い.ぬ・みたまや・や.める", "ゼン・ネン・しか・しか.り・しか.し・さ", "ハン・めし", "マツ・バツ・すえ", "タン・ひとえ", "シン・み", "モン・と.う・と.い・とん", "カク・かど・つの", "ショウ・ぬま", "ビ・ミ・うつく.しい", "タン・みじか.い", "ケイ・キョウ・キン・かる.い・かろ.やか・かろ.んじる", "ウ・は・わ・はね", "セン・ふね・ふな~", "ショウ・わら.う・え.む", "ガン・いわ", "ウン・くも・~ぐも", "メイ・な.く・な.る・な.らす", "キュウ・ゆみ", "コウ・みなと", "カイ・きざはし", "ロ・ル・~じ・みち", "アク・オ・わる.い・わる~・あ.し・にく.い・~にく.い・ああ・いずくに・いずくんぞ・にく.む", "タ・ほか", "キョウ・はし", "ガン・きし", "キャク・カク", "トウ・ト・ドウ・ショウ・チョウ・のぼ.る・あ.がる", "ソク・はや.い・はや~・はや.める・すみ.やか", "オウ"};
const string meanings[Overall_size] = {"one; one radical (no.1)", "two; two radical (no. 7)", "three", "four", "five", "six", "seven", "eight; eight radical (no. 12)", "nine", "ten", "hundred", "thousand", "ten thousand; 10,000", "circle; yen; round", "day; sun; Japan; counter for days", "week", "month; moon", "year; counter for years", "time; hour", "interval; space", "part; minute of time; segment; share; degree; one's lot; duty; understand; know; rate; 1%; chances; shaku/100", "noon; sign of the horse; 11AM-1PM; seventh sign of Chinese zodiac", "in front; before", "behind; back; later", "now", "before; ahead; previous; future; precedence", "come; due; next; cause; become", "half; middle; odd number; semi-; part-", "every", "what", "person", "male", "woman; female", "child; sign of the rat; 11PM-1AM; first sign of Chinese zodiac", "mother", "father", "friend", "fire", "water", "tree; wood", "soil; earth; ground; Turkey", "gold", "book; present; main; origin; true; real; counter for long cylindrical things", "stream; river; river or three-stroke river radical (no. 47)", "flower", "spirit; mind; air; atmosphere; mood", "life; genuine; birth", "fish", "heavens; sky; imperial", "empty; sky; void; vacant; vacuum", "mountain", "rain", "electricity", "car", "word; speech; language", "ear", "hand", "leg; foot; be sufficient; counter for pairs of footwear", "eye; class; look; insight; experience; care; favor", "mouth", "name; noted; distinguished; reputation", "store; shop", "station", "road-way; street; district; journey; course; moral; teachings", "company; firm; office; association; shrine", "country", "outside", "study; learning; science", "exam; school; printing; proof; correction", "above; up", "below; down; descend; give; low; inferior", "in; inside; middle; mean; center", "north", "east", "south", "west; Spain", "right", "left", "character; letter; word; section of village", "see; hopes; chances; idea; opinion; look at; visible", "hear; ask; listen", "write", "read", "tale; talk", "buy", "going; journey; carry out; conduct; act; line; row; bank", "exit; leave; go out; come out; put out; protrude", "enter; insert", "rest; day off; retire; sleep", "eat; food", "drink; smoke; take", "say; word", "stand up; rise; set up; erect", "meeting; meet; party; association; interview; join", "many; frequent; much", "few; little", "old", "new", "large; big", "little; small", "relax; cheap; low; quiet; rested; contented; peaceful", "tall; high; expensive", "long; leader; superior; senior", "white", "private; I; me", "dragon; imperial", "second (1/60 minute)", "sentence; literature; style; art; decoration; figures; plan; literary radical (no. 67)", "change; take the form of; influence; enchant; delude; -ization", "forest; woods", "guard; protect; defend; obey", "rice field; rice paddy", "generation; world; society; public", "death; die", "commence; begin", "wait; depend on", "someone; person", "Sino-; China", "weekday", "England; English; hero; outstanding; calyx", "power; strength; strong; strain; bear up; exert", "sound; noise", "dog", "direction; person; alternative", "ground; earth", "capital; 10**16", "utilize; business; service; use; employ", "house; home; family; professional; expert; performer", "brush-stroke; picture", "sea; ocean", "black", "springtime; spring (season)", "autumn", "summer", "winter", "daytime; noon", "tea", "run", "color", "younger brother; faithful service to elders", "elder brother; big brother", "younger sister", "elder sister", "love; affection; favourite", "fond; pleasing; like something", "icicle; ice; hail; freeze; congeal", "complete; finish", "body; substance; object; reality; counter for images", "length; ten shaku; measure; Mr.; Ms.; height; stature; all (one has); only; that's all; merely", "husband; man", "fur; hair; feather; down", "hold; have", "hit; right; appropriate; himself", "hole; aperture; slit; cave; den", "good; pleasing; skilled", "negative; non-; bad; ugly; clumsy", "newborn babe; child; young of animals", "stop; halt", "heart; mind; spirit; heart radical (no. 61)", "kanji iteration mark", "humanity; virtue; benevolence; charity; man; kernel", "-times; round; game; revolve; counter for occurrences", "carry; luck; destiny; fate; lot; transport; progress; advance", "same; agree; equal", "can; passable; mustn't; should not; do not", "he; that; the", "closed; shut", "permit; approve", "pour; irrigate; shed (tears); flow into; concentrate on; notes; comment; annotate", "whole; entire; all; complete; fulfill", "fit; suit; join; 0.1", "bright; light", "specialty; exclusive; mainly; solely", "transmit; go along; walk along; follow; report; communicate; legend; tradition", "voice", "next; order; sequence", "ancestor; pioneer; founder", "scribe; account; narrative", "matter; thing; fact; business; reason; possibly", "blue; green", "green", "yellow", "red", "purple; violet", "of; this", "craft; construction; katakana e radical (no. 48)", "precious; value; prize; esteem; honor", "protect; guarantee; keep; preserve; sustain; support", "safeguard; protect", "correct; justice; righteous; 10**40", "beginning; former time; origin", "next; order; sequence", "turn; number in a series", "usual; ordinary; normal; common; regular; continually; always; long-lasting", "Shinto shrine; constellations; palace; princess", "village; town", "prohibition; ban; forbid", "stone", "mutually; reciprocally; together", "I; myself", "take along; lead; join; connect; party; gang; clique", "cry; weep; moan", "cat", "bird; chicken", "west; bird; sign of the bird; 5-7PM; tenth sign of Chinese zodiac; sake radical (no. 164)", "oneself", "nightfall; night", "inside; within; between; among; house; home", "memorize; learn; remember; awake; sober up", "plump; thick; big around", "harden; set; clot; curdle", "long time; old story", "waves; billows; Poland", "daughter; girl", "breath; respiration; son; interest (on money)", "night; evening", "cramped; narrow; contract; tight", "suffering; trial; worry; hardship; feel bitter; scowl", "early; fast", "slow; late; back; later", "method; law; rule; principle; model; system", "dwell; reside; live; inhabit", "lord; chief; master; main thing; principal", "uncanny; weird; threatening; horrible", "wife; spouse", "rice plant", "responsibility; duty; term; entrust to; appoint", "music; comfort; ease", "difficult; impossible; trouble; accident; defect", "distinction; difference; variation; discrepancy; margin; balance", "jewel; ball", "egg; ovum; spawn; roe", "slip out; extract; pull out; pilfer; quote; remove; omit", "loins; hips; waist; low wainscoting", "fog; mist", "shadow; silhouette; phantom", "island", "root; radical; head (pimple)", "roof; house; shop; dealer; seller", "tribe; family", "grass; weeds; herbs; pasture; write; draft", "bamboo", "sex; gender; nature", "status; rank; capacity; character; case (law, grammar)", "bull's eye; mark; target; object; adjective ending", "tool; utensil; means; possess; ingredients; counter for armor, suits, sets of furniture", "assets; resources; capital; funds; data; be conducive to; contribute to", "occasion; side; edge; verge; dangerous; adventurous; indecent; time; when", "reality; truth", "give; bestow; perform; alms", "linen; cloth; spread; distribute", "together; both; neither; all; and; alike; with", "possess; have; exist; happen; occur; approx", "stick; paste; apply", "gain; get; find; earn; acquire; can; may; able to; profit; advantage; benefit", "idea; mind; heart; taste; thought; desire; care; liking", "shake; wave; wag; swing", "crowded; mixture; in bulk; included; (kokuji)", "return; answer; fade; repay", "use; send on a mission; order; messenger; envoy; ambassador; cause", "building; mansion; large building; palace", "map; drawing; plan; extraordinary; audacious", "posture; build; pretend", "pipe; tube; wind instrument; drunken talk; control; jurisdiction", "logic; arrangement; reason; justice; truth", "general; whole; all; full; total", "elect; select; choose; prefer", "beforehand; previous; myself; I", "ward off; defend; protect; resist", "determine; fix; establish; decide", "tongue; reed; clapper", "even; flat; peace", "resign; word; term; expression", "code; ceremony; law; rule", "person in charge; connection; duty; concern oneself", "number; strength; fate; law; figures", "utmost; most; extreme", "first time; beginning", "contact; touch; feel; hit; proclaim; announce; conflict", "mediator; go-between", "accept; undergo; answer (phone); take; get; catch; receive", "take; fetch; take up", "unusual; change; strange", "open; unfold; unseal", "even; flat; peace", "bend; music; melody; composition; pleasure; injustice; fault; curve; crooked; perverse; lean", "line; track", "king; rule; magnate", "employee; member; number; the one in charge", "valve; petal; braid; speech; dialect; discrimination; dispose of; distinguish; conical cap", "gentleman; scholar; samurai; samurai radical (no. 33)", "face; expression", "mask; face; features; surface", "pond; cistern; pool; reservoir", "marsh; lake; bog; swamp; pond", "choose; select; elect; prefer", "town; village; block; street", "snow", "shellfish", "thread", "insect; bug; temper", "grove; forest", "location; place", "rice; USA; metre", "traffic; pass through; avenue; commute; counter for letters, notes, documents, etc.", "neck; counter for songs and poems", "make; production; prepare; build", "strong", "market; city; town", "public; prince; official; governmental", "plains; field; rustic; civilian life", "think", "spot; point; mark; speck; decimal point", "lively; resuscitation; being helped; living", "meadow; original; primitive; field; plain; prairie; tundra; wilderness", "mingle; mixing; association; coming & going", "near; early; akin; tantamount", "consider; think over", "sell", "association; braid; plait; construct; assemble; unite; cooperate; grapple", "know; wisdom", "pull; tug; jerk; admit; install; quote; refer to", "plot; plan; scheme; measure", "straightaway; honesty; frankness; fix; repair", "morning; dynasty; regime; epoch; period; (North) Korea", "pedestal; a stand; counter for machines and vehicles", "wide; broad; spacious", "evening", "teach; faith; doctrine", "cut; cutoff; be sharp", "calculate; divining; number; abacus; probability", "parent; intimacy; relative; familiarity; dealer (cards)", "shape; form; style", "head; counter for large animals", "gate; counter for cannons", "solution; answer", "homecoming; arrive at; lead to; result in", "valley", "song; sing", "ray; light", "department; course; section", "dainty; get thin; taper; slender; narrow; detailed; precise", "round; full (month); perfection; -ship; pills; make round; roll up; curl up; seduce; explain away", "room; apartment; chamber; greenhouse; cellar", "walk; counter for steps", "wind; air; style; manner", "paper", "door; counter for houses; door radical (no. 63)", "park; garden; yard; farm", "fee; materials", "nothingness; none; ain't; nothing; nil; not", "No.; residence", "world; boundary", "year-end; age; occasion; opportunity", "mister; you; ruler; male name suffix", "risk; face; defy; dare; damage; assume (a name)", "revolve; turn around; change", "occasion; side; edge; verge; dangerous; adventurous; indecent; time; when", "accomplished; reach; arrive; attain", "witch; demon; evil spirit", "uncommon; different; queerness; strangeness; wonderful; curious; unusual", "reflect; reflection; projection", "exertion; endeavour; encourage; strive; make effort; diligent", "rouse; wake up; get up", "lie down; sleep; rest; bed; remain unsold", "sort of thing; so; if so; in that case; well", "meal; boiled rice", "end; close; tip; powder; posterity", "simple; one; single; merely", "somebody; person; one's station in life", "question; ask; problem", "angle; corner; square; horn; antlers", "marsh; lake; bog; swamp; pond", "beauty; beautiful", "short; brevity; fault; defect; weak point", "lightly; trifling; unimportant", "feathers; counter for birds, rabbits", "ship; boat", "laugh", "boulder; rock; cliff", "cloud", "chirp; cry; bark; sound; ring; echo; honk", "bow; bow (archery, violin)", "harbor", "storey; stair; counter for storeys of a building", "path; route; road; distance", "bad; vice; rascal; false; evil; wrong", "other; another; the others", "bridge", "beach", "guest; visitor; customer; client", "ascend; climb up", "quick; fast", "center; middle"};
string str;

bool flash_cards(int randomNumber, vector<int>& forgotten, int num, bool& go_to_forgotten, bool& new_forgotten){
    

    cout << "\n█▄▀ ▄▀█ █▄░█ ░░█ █   █▀▀ █░░ ▄▀█ █▀ █░█   █▀▀ ▄▀█ █▀█ █▀▄ █▀\n" << 
              "█░█ █▀█ █░▀█ █▄█ █   █▀░ █▄▄ █▀█ ▄█ █▀█   █▄▄ █▀█ █▀▄ █▄▀ ▄█\n\n" << std::endl;

    cout << num << ". " << kanji[randomNumber].kanji << ' ';
    
    while(getline(cin, str)){
        for (int i = 0; i < str.length(); i++){
            str[i] = tolower(str[i]);
        }

        if(str.empty()){
            cout<< "----------" << '\n';
            cout << "readings: " << readings[randomNumber] << '\n';
            cout << "meanings: " << meanings[randomNumber] << "\n";

            while(getline(cin, str)){
                for (int i = 0; i < str.length(); i++){
                    str[i] = tolower(str[i]);
                }

                if(str.empty()){
                    system("clear");
                    return false;

                } else if (str == "e"){
                    return true;

                } else if (str != "q" && str != "e" && !str.empty()){
                    forgotten.push_back(randomNumber);
                    system("clear");
                    new_forgotten = true;
                    return false;
                } else if (str == "q"){
                    system("clear");
                    go_to_forgotten = true;
                    return false;
                }
            }  
             
        } else if (str == "e"){
            return true;

        } else if (str != "q" && str != "e" && !str.empty()){
            forgotten.push_back(randomNumber);
            system("clear");
            new_forgotten = true;
            return false;

        } else if (str == "q"){
            system("clear");
            go_to_forgotten = true;
            return false;
        }

    } 

    return false;
}

int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, Overall_size - 1);

    bool go_to_forgotten = false, new_forgotten = false;
    int randomNumber, num = 1;

    vector<int> forgotten;
    vector<int> next_round;

    while(num <= Overall_size){
        randomNumber = distr(gen);

        if(kanji[randomNumber].was_shown != true){
            kanji[randomNumber].was_shown = true;

            if(flash_cards(randomNumber, forgotten, num, go_to_forgotten, new_forgotten)){
                return 0;
            } 
            if(go_to_forgotten && forgotten.size() != 0){
                break;
            }
            num++;
            
        }

    }
    
    while(true){
        if(forgotten.size() == 0 && next_round.size() == 0){
            cout << "You did everything, congratulations:D" << "\n";
            while(getline(cin, str)){
                if(str.empty()){
                    system("clear");
                    return 0;
                }
            } 
        } else {
            cout << "Wait... you forgot some? Lets try again then";
            int y = forgotten.size();
            
            for(int i = 0; i < y; i++){
                go_to_forgotten = false;
                randomNumber = forgotten.back();

                if(flash_cards(randomNumber, forgotten, i + 1, go_to_forgotten, new_forgotten)){
                    return 0;
                } 
                if(new_forgotten){
                    next_round.push_back(forgotten.back());
                    forgotten.pop_back();
                }
                new_forgotten = false;
                forgotten.pop_back();
                
                
            }
            while(next_round.size() != 0){
                forgotten.push_back(next_round.back());
                next_round.pop_back();
            }
        }
    }
      
    return 0;
}