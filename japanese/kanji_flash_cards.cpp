#include <iostream>
#include <vector>
#include <random>
using namespace std;
const int SIZE = 394;

const string kanji[SIZE] = {"一", "二", "三", "四", "五", "六", "七", "八", "九", "十", "百", "千", "万", "円", "日", "週", "月", "年", "時", "間", "分", "午", "前", "後", "今", "先", "来", "半", "毎", "何", "人", "男", "女", "子", "母", "父", "友", "火", "水", "木", "土", "金", "本", "川", "花", "気", "生", "魚", "天", "空", "山", "雨", "電", "車", "語", "耳", "手", "足", "目", "口", "名", "店", "駅", "道", "社", "国", "外", "学", "校", "上", "下", "中", "北", "東", "南", "西", "右", "左", "字", "見", "聞", "書", "読", "話", "買", "行", "出", "入", "休", "食", "飲", "言", "立", "会", "多", "少", "古", "新", "大", "小", "安", "高", "長", "白", "私", "竜", "秒", "文", "化", "森", "守", "田", "世", "死", "始", "待", "者", "漢", "曜", "英", "力", "音", "犬", "方", "地", "京", "用", "家", "画", "海", "黒", "春", "秋", "夏", "冬", "昼", "茶", "走", "色", "弟", "兄", "妹", "姉", "愛", "好", "氷", "了", "体", "丈", "夫", "毛", "持", "当", "穴", "良", "不", "児", "止", "心", "々", "仁", "回", "運", "同", "可", "彼", "閉", "許", "注", "全", "合", "明", "専", "伝", "声", "次", "祖", "記", "事", "青", "緑", "黄", "赤", "紫", "之", "工", "貴", "保", "護", "正", "元", "次", "番", "常", "宮", "村", "禁", "石", "互", "俺", "連", "泣", "猫", "鳥", "酉", "自", "晩", "内", "覚", "太", "固", "久", "波", "娘", "息", "夜", "狭", "苦", "早", "遅", "法", "住", "主", "凄", "妻", "稲", "任", "楽", "難", "差", "玉", "卵", "抜", "腰", "霧", "影", "島", "根", "屋", "族", "草", "竹", "性", "格", "的", "具", "資", "際", "実", "施", "布", "共", "有", "貼", "得", "意", "振", "込", "返", "使", "館", "図", "構", "管", "理", "総", "選", "予", "防", "定", "舌", "平", "辞", "典", "係", "数", "最", "初", "触", "媒", "受", "取", "変", "開", "平", "曲", "線", "王", "員", "弁", "士", "顔", "面", "池", "沼", "択", "町", "雪", "貝", "糸", "虫", "林", "場", "米", "通", "首", "作", "強", "市", "公", "野", "思", "点", "活", "原", "交", "近", "考", "売", "組", "知", "引", "計", "直", "朝", "台", "広", "夕", "教", "切", "算", "親", "形", "頭", "門", "答", "帰", "谷", "歌", "光", "科", "細", "丸", "室", "歩", "風", "紙", "戸", "園", "料", "無", "第", "界", "歳", "君", "冒", "転", "際", "達", "魔", "異", "映", "勉", "起", "寝", "然", "飯", "末", "単", "身", "問", "角", "沼", "美", "短", "軽", "羽", "船", "笑", "岩", "雲", "鳴", "弓", "港", "階", "路", "悪", "他", "橋", "岸", "客", "登", "速", "央"};
const string readings[SIZE] = {"イチ・イツ・ひと~・ひと.つ", "ニ・ジ・ふた・ふた.つ・ふたたび", "サン・ゾウ・み・み.つ・みっ.つ", "シ・よ・よ.つ・よっ.つ・よん", "ゴ・いつ・いつ.つ", "ロク・リク・む・む.つ・むっ.つ・むい", "シチ・なな・なな.つ・なの", "ハチ・や・や.つ・やっ.つ・よう", "キュウ・ク・ここの・ここの.つ", "ジュウ・ジッ・ジュッ・とお・と", "ヒャク・ビャク・もも", "セン・ち", "マン・バン・よろず", "エン・まる.い・まる・まど・まど.か・まろ.やか", "ニチ・ジツ・ひ・~び・~か", "シュウ", "ゲツ・ガツ・つき", "ネン・とし", "ジ・とき・~どき", "カン・ケン・あいだ・ま・あい", "ブン・フン・ブ・わ.ける・わ.け・わ.かれる・わ.かる・わ.かつ", "ゴ・うま", "ゼン・まえ・~まえ", "ゴ・コウ・のち・うし.ろ・うしろ・あと・おく.れる", "コン・キン・いま", "セン・さき・ま.ず", "ライ・タイ・く.る・きた.る・きた.す・き.たす・き.たる・き・こ", "ハン・なか.ば", "マイ・ごと・~ごと.に", "カ・なに・なん・なに~・なん~", "ジン・ニン・ひと・~り・~と", "ダン・ナン・おとこ・お", "ジョ・ニョ・ニョウ・おんな・め", "シ・ス・ツ・こ・~こ・ね", "ボ・はは・も", "フ・ちち", "ユウ・とも", "カ・ひ・~び・ほ~", "スイ・みず・みず~", "ボク・モク・き・こ~", "ド・ト・つち", "キン・コン・ゴン・かね・かな~・~がね", "ホン・もと", "セン・かわ", "カ・ケ・はな", "キ・ケ・いき", "セイ・ショウ・い.きる・い.かす・い.ける・う.まれる・うま.れる・う.まれ・うまれ・う.む・お.う・は.える・は.やす・き・なま・なま~・な.る・な.す・む.す・~う", "ギョ・うお・さかな・~ざかな", "テン・あまつ・あめ・あま~", "クウ・そら・あ.く・あ.き・あ.ける・から・す.く・す.かす・むな.しい", "サン・セン・やま", "ウ・あめ・あま~・~さめ", "デン", "シャ・くるま", "ゴ・かた.る・かた.らう", "ジ・みみ", "シュ・ズ・て・て~・~て・た~", "ソク・あし・た.りる・た.る・た.す", "モク・ボク・め・~め・ま~", "コウ・ク・くち", "メイ・ミョウ・な・~な", "テン・みせ・たな", "エキ", "ドウ・トウ・みち・いう", "シャ・やしろ", "コク・くに", "ガイ・ゲ・そと・ほか・はず.す・はず.れる・と~", "ガク・まな.ぶ", "コウ・キョウ", "ジョウ・ショウ・シャン・うえ・~うえ・うわ~・かみ・あ.げる・~あ.げる・あ.がる・~あ.がる・あ.がり・~あ.がり・のぼ.る・のぼ.り・のぼ.せる・のぼ.す・たてまつ.る", "カ・ゲ・した・しも・もと・さ.げる・さ.がる・くだ.る・くだ.り・くだ.す・~くだ.す・くだ.さる・お.ろす・お.りる", "チュウ・なか・うち・あた.る", "ホク・きた", "トウ・ひがし", "ナン・ナ・みなみ", "セイ・サイ・ス・にし", "ウ・ユウ・みぎ", "サ・シャ・ひだり", "ジ・あざ・あざな・~な", "ケン・み.る・み.える・み.せる", "ブン・モン・き.く・き.こえる", "ショ・か.く・~が.き・~がき", "ドク・トク・トウ・よ.む・~よ.み", "ワ・はな.す・はなし", "バイ・か.う", "コウ・ギョウ・アン・い.く・ゆ.く・~ゆ.き・~ゆき・~い.き・~いき・おこな.う・おこ.なう", "シュツ・スイ・で.る・~で・だ.す・~だ.す・い.でる・い.だす", "ニュウ・ジュ・い.る・~い.る・~い.り・い.れる・~い.れ・はい.る", "キュウ・やす.む・やす.まる・やす.める", "ショク・ジキ・く.う・く.らう・た.べる・は.む", "イン・オン・の.む・~の.み", "ゲン・ゴン・い.う・こと", "リツ・リュウ・リットル・た.つ・~た.つ・た.ち~・た.てる・~た.てる・た.て~・たて~・~た.て・~だ.て・~だ.てる", "カイ・エ・あ.う・あ.わせる・あつ.まる", "タ・おお.い・まさ.に・まさ.る", "ショウ・すく.ない・すこ.し", "コ・ふる.い・ふる~・~ふる.す", "シン・あたら.しい・あら.た・あら~・にい~", "ダイ・タイ・おお~・おお.きい・~おお.いに", "ショウ・ちい.さい・こ~・お~・さ~", "アン・やす.い・やす.まる・やす・やす.らか", "コウ・たか.い・たか・~だか・たか.まる・たか.める", "チョウ・なが.い・おさ", "ハク・ビャク・しろ・しら~・しろ.い", "シ・わたくし・わたし", "リュウ・リョウ・ロウ・たつ・いせ", "ビョウ", "ブン・モン・ふみ・あや", "カ・ケ・ば.ける・ば.かす・ふ.ける・け.する", "シン・もり", "シュ・ス・まも.る・まも.り・もり・~もり・かみ", "デン・た", "セイ・セ・ソウ・よ", "シ・し.ぬ・し.に~", "シ・はじ.める・~はじ.める・はじ.まる", "タイ・ま.つ・~ま.ち", "シャ・もの", "カン", "ヨウ", "エイ・はなぶさ", "リョク・リキ・リイ・ちから", "オン・イン・~ノン・おと・ね", "ケン・いぬ・いぬ~", "ホウ・かた・~かた・~がた", "チ・ジ", "キョウ・ケイ・キン・みやこ", "ヨウ・もち.いる", "カ・ケ・いえ・や・うち", "ガ・カク・エ・カイ・えが.く・かく.する・かぎ.る・はかりごと・はか.る", "カイ・うみ", "コク・くろ・くろ.ずむ・くろ.い", "シュン・はる", "シュウ・あき・とき", "カ・ガ・ゲ・なつ", "トウ・ふゆ", "チュウ・ひる", "チャ・サ", "ソウ・はし.る", "ショク・シキ・いろ", "テイ・ダイ・デ・おとうと", "ケイ・キョウ・あに", "マイ・いもうと", "シ・あね・はは", "アイ・いと.しい・かな.しい・め.でる・お.しむ・まな", "コウ・この.む・す.く・よ.い・い.い", "ヒョウ・こおり・ひ・こお.る", "リョウ", "タイ・テイ・からだ・かたち", "ジョウ・たけ・だけ", "フ・フウ・ブ・おっと・それ", "モウ・け", "ジ・も.つ・~も.ち・も.てる", "トウ・あ.たる・あ.たり・あ.てる・あ.て・まさ.に・まさ.にべし", "ケツ・あな", "リョウ・よ.い・~よ.い・い.い・~い.い", "フ・ブ", "ジ・ニ・ゲイ・こ・~こ・~っこ", "シ・と.まる・~ど.まり・と.める・~と.める・~ど.め・とど.める・とど.め・とど.まる・や.める・や.む・~や.む・よ.す・~さ.す・~さ.し", "シン・こころ・~ごころ", "のま", "ジン・ニ・ニン", "カイ・エ・まわ.る・~まわ.る・~まわ.り・まわ.す・~まわ.す・まわ.し~・~まわ.し・もとお.る・か.える", "ウン・はこ.ぶ", "ドウ・おな.じ", "カ・コク・~べ.き・~べ.し", "ヒ・かれ・かの・か.の", "ヘイ・と.じる・と.ざす・し.める・し.まる・た.てる", "キョ・ゆる.す・もと", "チュウ・そそ.ぐ・さ.す・つ.ぐ", "ゼン・まった.く・すべ.て", "ゴウ・ガッ・カッ・あ.う・~あ.う・あ.い・あい~・~あ.い・~あい・あ.わす・あ.わせる・~あ.わせる", "メイ・ミョウ・ミン・あ.かり・あか.るい・あか.るむ・あか.らむ・あき.らか・あ.ける・~あ.け・あ.く・あ.くる・あ.かす", "セン・もっぱ.ら", "デン・テン・つた.わる・つた.える・つた.う・つだ.う・~づた.い・つて", "セイ・ショウ・こえ・こわ~", "ジ・シ・つ.ぐ・つぎ", "ソ", "キ・しる.す", "ジ・ズ・こと・つか.う・つか.える", "セイ・ショウ・あお・あお~・あお.い", "リョク・ロク・みどり", "コウ・オウ・き・こ~", "セキ・シャク・あか・あか~・あか.い・あか.らむ・あか.らめる", "シ・むらさき", "シ・の・これ・ゆく・この", "コウ・ク・グ", "キ・たっと.い・とうと.い・たっと.ぶ・とうと.ぶ", "ホ・ホウ・たも.つ", "ゴ・まも.る", "セイ・ショウ・ただ.しい・ただ.す・まさ・まさ.に", "ゲン・ガン・もと", "ジ・シ・つ.ぐ・つぎ", "バン・つが.い", "ジョウ・つね・とこ~", "キュウ・グウ・ク・クウ・みや", "ソン・むら", "キン", "セキ・シャク・コク・いし", "ゴ・たが.い・かたみ.に", "エン・おれ・われ", "レン・つら.なる・つら.ねる・つ.れる・~づ.れ", "キュウ・な.く", "ビョウ・ねこ", "チョウ・とり", "ユウ・とり", "ジ・シ・みずか.ら・おの.ずから・おの.ずと", "バン", "ナイ・ダイ・うち", "カク・おぼ.える・さ.ます・さ.める・さと.る", "タイ・タ・ふと.い・ふと.る", "コ・かた.める・かた.まる・かた.まり・かた.い", "キュウ・ク・ひさ.しい", "ハ・なみ", "ジョウ・むすめ・こ", "ソク・いき", "ヤ・よ・よる", "キョウ・コウ・せま.い・せば.める・せば.まる・さ", "ク・くる.しい・~ぐる.しい・くる.しむ・くる.しめる・にが.い・にが.る", "ソウ・サッ・はや.い・はや・はや~・はや.まる・はや.める・さ~", "チ・おく.れる・おく.らす・おそ.い", "ホウ・ハッ・ホッ・フラン・のり", "ジュウ・ヂュウ・チュウ・す.む・す.まう・~ず.まい", "シュ・ス・シュウ・ぬし・おも・あるじ", "セイ・サイ・さむ.い・すご.い・すさ.まじい", "サイ・つま", "トウ・テ・いね・いな~", "ニン・まか.せる・まか.す", "ガク・ラク・ゴウ・たの.しい・たの.しむ・この.む", "ナン・かた.い・~がた.い・むずか.しい・むづか.しい・むつか.しい・~にく.い", "サ・さ.す・さ.し", "ギョク・たま・たま~・~だま", "ラン・たまご", "バツ・ハツ・ハイ・ぬ.く・~ぬ.く・ぬ.き・ぬ.ける・ぬ.かす・ぬ.かる", "ヨウ・こし", "ム・ボウ・ブ・きり", "エイ・かげ", "トウ・しま", "コン・ね・~ね", "オク・や", "ゾク", "ソウ・くさ・くさ~・~ぐさ", "チク・たけ", "セイ・ショウ・さが", "カク・コウ・キャク・ゴウ", "テキ・まと", "グ・そな.える・つぶさ.に", "シ", "サイ・きわ・~ぎわ", "ジツ・シツ・み・みの.る・まこと・みの・みち.る", "シ・セ・ほどこ.す", "フ・ぬの", "キョウ・とも・とも.に・~ども", "ユウ・ウ・あ.る", "テン・チョウ・は.る・つ.く", "トク・え.る・う.る", "イ", "シン・ふ.る・ぶ.る・ふ.り・~ぶ.り・ふ.るう", "~こ.む・こ.む・こ.み・~こ.み・こ.める", "ヘン・かえ.す・~かえ.す・かえ.る・~かえ.る", "シ・つか.う・つか.い・~つか.い・~づか.い", "カン・やかた・たて", "ズ・ト・え・はか.る", "コウ・かま.える・かま.う", "カン・くだ", "リ・ことわり", "ソウ・す.べて・すべ.て・ふさ", "セン・えら.ぶ", "ヨ・シャ・あらかじ.め", "ボウ・ふせ.ぐ", "テイ・ジョウ・さだ.める・さだ.まる・さだ.か", "ゼツ・した", "ヘイ・ビョウ・ヒョウ・たい.ら・~だいら・ひら・ひら~", "ジ・や.める・いな.む", "テン・デン", "ケイ・かか.る・かかり・~がかり・かか.わる", "スウ・ス・サク・ソク・シュ・かず・かぞ.える・しばしば・せ.める・わずらわ.しい", "サイ・シュ・もっと.も・つま", "ショ・はじ.め・はじ.めて・はつ・はつ~・うい~・~そ.める・~ぞ.め", "ショク・ふ.れる・さわ.る・さわ", "バイ・なこうど", "ジュ・う.ける・~う.け・う.かる", "シュ・と.る・と.り・と.り~・とり・~ど.り", "ヘン・か.わる・か.わり・か.える", "カイ・ひら.く・ひら.き・~びら.き・ひら.ける・あ.く・あ.ける", "ヘイ・ビョウ・ヒョウ・たい.ら・~だいら・ひら・ひら~", "キョク・ま.がる・ま.げる・くま", "セン・すじ", "オウ・~ノウ", "イン", "ベン・ヘン・かんむり・わきま.える・わ.ける・はなびら・あらそ.う", "シ・さむらい", "ガン・かお", "メン・ベン・おも・おもて・つら", "チ・いけ", "ショウ・ぬま", "タク・えら.ぶ", "チョウ・まち", "セツ・ゆき", "バイ・かい", "シ・いと", "チュウ・キ・むし", "リン・はやし", "ジョウ・チョウ・ば", "ベイ・マイ・メエトル・こめ・よね", "ツウ・ツ・とお.る・とお.り・~とお.り・~どお.り・とお.す・とお.し・~どお.し・かよ.う", "シュ・くび", "サク・サ・つく.る・つく.り・~づく.り", "キョウ・ゴウ・つよ.い・つよ.まる・つよ.める・し.いる・こわ.い", "シ・いち", "コウ・ク・おおやけ", "ヤ・ショ・の・の~", "シ・おも.う・おもえら.く・おぼ.す", "テン・つ.ける・つ.く・た.てる・さ.す・とぼ.す・とも.す・ぼち", "カツ・い.きる・い.かす・い.ける", "ゲン・はら", "コウ・まじ.わる・まじ.える・ま.じる・まじ.る・ま.ざる・ま.ぜる・~か.う・か.わす・かわ.す・こもごも", "キン・コン・ちか.い", "コウ・かんが.える・かんが.え", "バイ・う.る・う.れる", "ソ・く.む・くみ・~ぐみ", "チ・し.る・し.らせる", "イン・ひ.く・ひ.き・ひ.き~・~び.き・ひ.ける", "ケイ・はか.る・はか.らう", "チョク・ジキ・ジカ・ただ.ちに・なお.す・~なお.す・なお.る・なお.き・す.ぐ", "チョウ・あさ", "ダイ・タイ・うてな・われ・つかさ", "コウ・ひろ.い・ひろ.まる・ひろ.める・ひろ.がる・ひろ.げる", "セキ・ゆう", "キョウ・おし.える・おそ.わる", "セツ・サイ・き.る・~き.る・き.り・~き.り・~ぎ.り・き.れる・~き.れる・き.れ・~き.れ・~ぎ.れ", "サン・そろ", "シン・おや・おや~・した.しい・した.しむ", "ケイ・ギョウ・かた・~がた・かたち・なり", "トウ・ズ・ト・あたま・かしら・~がしら・かぶり", "モン・かど・と", "トウ・こた.える・こた.え", "キ・かえ.る・かえ.す・おく.る・とつ.ぐ", "コク・たに・きわ.まる", "カ・うた・うた.う", "コウ・ひか.る・ひかり", "カ", "サイ・ほそ.い・ほそ.る・こま.か・こま.かい", "ガン・まる・まる.める・まる.い", "シツ・むろ", "ホ・ブ・フ・ある.く・あゆ.む", "フウ・フ・かぜ・かざ~・~かぜ", "シ・かみ", "コ・と", "エン・その", "リョウ", "ム・ブ・な.い", "ダイ・テイ", "カイ", "サイ・セイ・とし・とせ・よわい", "クン・きみ・~ぎみ", "ボウ・おか.す", "テン・ころ.がる・ころ.げる・ころ.がす・ころ.ぶ・まろ.ぶ・うたた・うつ.る・くる.めく", "サイ・きわ・~ぎわ", "タツ・ダ・~たち", "マ", "イ・こと・こと.なる・け", "エイ・うつ.る・うつ.す・は.える・~ば.え", "ベン・つと.める", "キ・お.きる・お.こる・お.こす・おこ.す・た.つ", "シン・ね.る・ね.かす・い.ぬ・みたまや・や.める", "ゼン・ネン・しか・しか.り・しか.し・さ", "ハン・めし", "マツ・バツ・すえ", "タン・ひとえ", "シン・み", "モン・と.う・と.い・とん", "カク・かど・つの", "ショウ・ぬま", "ビ・ミ・うつく.しい", "タン・みじか.い", "ケイ・キョウ・キン・かる.い・かろ.やか・かろ.んじる", "ウ・は・わ・はね", "セン・ふね・ふな~", "ショウ・わら.う・え.む", "ガン・いわ", "ウン・くも・~ぐも", "メイ・な.く・な.る・な.らす", "キュウ・ゆみ", "コウ・みなと", "カイ・きざはし", "ロ・ル・~じ・みち", "アク・オ・わる.い・わる~・あ.し・にく.い・~にく.い・ああ・いずくに・いずくんぞ・にく.む", "タ・ほか", "キョウ・はし", "ガン・きし", "キャク・カク", "トウ・ト・ドウ・ショウ・チョウ・のぼ.る・あ.がる", "ソク・はや.い・はや~・はや.める・すみ.やか", "オウ"};
const string meanings[SIZE] = {"one; one radical (no.1)", "two; two radical (no. 7)", "three", "four", "five", "six", "seven", "eight; eight radical (no. 12)", "nine", "ten", "hundred", "thousand", "ten thousand; 10,000", "circle; yen; round", "day; sun; Japan; counter for days", "week", "month; moon", "year; counter for years", "time; hour", "interval; space", "part; minute of time; segment; share; degree; one's lot; duty; understand; know; rate; 1%; chances; shaku/100", "noon; sign of the horse; 11AM-1PM; seventh sign of Chinese zodiac", "in front; before", "behind; back; later", "now", "before; ahead; previous; future; precedence", "come; due; next; cause; become", "half; middle; odd number; semi-; part-", "every", "what", "person", "male", "woman; female", "child; sign of the rat; 11PM-1AM; first sign of Chinese zodiac", "mother", "father", "friend", "fire", "water", "tree; wood", "soil; earth; ground; Turkey", "gold", "book; present; main; origin; true; real; counter for long cylindrical things", "stream; river; river or three-stroke river radical (no. 47)", "flower", "spirit; mind; air; atmosphere; mood", "life; genuine; birth", "fish", "heavens; sky; imperial", "empty; sky; void; vacant; vacuum", "mountain", "rain", "electricity", "car", "word; speech; language", "ear", "hand", "leg; foot; be sufficient; counter for pairs of footwear", "eye; class; look; insight; experience; care; favor", "mouth", "name; noted; distinguished; reputation", "store; shop", "station", "road-way; street; district; journey; course; moral; teachings", "company; firm; office; association; shrine", "country", "outside", "study; learning; science", "exam; school; printing; proof; correction", "above; up", "below; down; descend; give; low; inferior", "in; inside; middle; mean; center", "north", "east", "south", "west; Spain", "right", "left", "character; letter; word; section of village", "see; hopes; chances; idea; opinion; look at; visible", "hear; ask; listen", "write", "read", "tale; talk", "buy", "going; journey; carry out; conduct; act; line; row; bank", "exit; leave; go out; come out; put out; protrude", "enter; insert", "rest; day off; retire; sleep", "eat; food", "drink; smoke; take", "say; word", "stand up; rise; set up; erect", "meeting; meet; party; association; interview; join", "many; frequent; much", "few; little", "old", "new", "large; big", "little; small", "relax; cheap; low; quiet; rested; contented; peaceful", "tall; high; expensive", "long; leader; superior; senior", "white", "private; I; me", "dragon; imperial", "second (1/60 minute)", "sentence; literature; style; art; decoration; figures; plan; literary radical (no. 67)", "change; take the form of; influence; enchant; delude; -ization", "forest; woods", "guard; protect; defend; obey", "rice field; rice paddy", "generation; world; society; public", "death; die", "commence; begin", "wait; depend on", "someone; person", "Sino-; China", "weekday", "England; English; hero; outstanding; calyx", "power; strength; strong; strain; bear up; exert", "sound; noise", "dog", "direction; person; alternative", "ground; earth", "capital; 10**16", "utilize; business; service; use; employ", "house; home; family; professional; expert; performer", "brush-stroke; picture", "sea; ocean", "black", "springtime; spring (season)", "autumn", "summer", "winter", "daytime; noon", "tea", "run", "color", "younger brother; faithful service to elders", "elder brother; big brother", "younger sister", "elder sister", "love; affection; favourite", "fond; pleasing; like something", "icicle; ice; hail; freeze; congeal", "complete; finish", "body; substance; object; reality; counter for images", "length; ten shaku; measure; Mr.; Ms.; height; stature; all (one has); only; that's all; merely", "husband; man", "fur; hair; feather; down", "hold; have", "hit; right; appropriate; himself", "hole; aperture; slit; cave; den", "good; pleasing; skilled", "negative; non-; bad; ugly; clumsy", "newborn babe; child; young of animals", "stop; halt", "heart; mind; spirit; heart radical (no. 61)", "kanji iteration mark", "humanity; virtue; benevolence; charity; man; kernel", "-times; round; game; revolve; counter for occurrences", "carry; luck; destiny; fate; lot; transport; progress; advance", "same; agree; equal", "can; passable; mustn't; should not; do not", "he; that; the", "closed; shut", "permit; approve", "pour; irrigate; shed (tears); flow into; concentrate on; notes; comment; annotate", "whole; entire; all; complete; fulfill", "fit; suit; join; 0.1", "bright; light", "specialty; exclusive; mainly; solely", "transmit; go along; walk along; follow; report; communicate; legend; tradition", "voice", "next; order; sequence", "ancestor; pioneer; founder", "scribe; account; narrative", "matter; thing; fact; business; reason; possibly", "blue; green", "green", "yellow", "red", "purple; violet", "of; this", "craft; construction; katakana e radical (no. 48)", "precious; value; prize; esteem; honor", "protect; guarantee; keep; preserve; sustain; support", "safeguard; protect", "correct; justice; righteous; 10**40", "beginning; former time; origin", "next; order; sequence", "turn; number in a series", "usual; ordinary; normal; common; regular; continually; always; long-lasting", "Shinto shrine; constellations; palace; princess", "village; town", "prohibition; ban; forbid", "stone", "mutually; reciprocally; together", "I; myself", "take along; lead; join; connect; party; gang; clique", "cry; weep; moan", "cat", "bird; chicken", "west; bird; sign of the bird; 5-7PM; tenth sign of Chinese zodiac; sake radical (no. 164)", "oneself", "nightfall; night", "inside; within; between; among; house; home", "memorize; learn; remember; awake; sober up", "plump; thick; big around", "harden; set; clot; curdle", "long time; old story", "waves; billows; Poland", "daughter; girl", "breath; respiration; son; interest (on money)", "night; evening", "cramped; narrow; contract; tight", "suffering; trial; worry; hardship; feel bitter; scowl", "early; fast", "slow; late; back; later", "method; law; rule; principle; model; system", "dwell; reside; live; inhabit", "lord; chief; master; main thing; principal", "uncanny; weird; threatening; horrible", "wife; spouse", "rice plant", "responsibility; duty; term; entrust to; appoint", "music; comfort; ease", "difficult; impossible; trouble; accident; defect", "distinction; difference; variation; discrepancy; margin; balance", "jewel; ball", "egg; ovum; spawn; roe", "slip out; extract; pull out; pilfer; quote; remove; omit", "loins; hips; waist; low wainscoting", "fog; mist", "shadow; silhouette; phantom", "island", "root; radical; head (pimple)", "roof; house; shop; dealer; seller", "tribe; family", "grass; weeds; herbs; pasture; write; draft", "bamboo", "sex; gender; nature", "status; rank; capacity; character; case (law, grammar)", "bull's eye; mark; target; object; adjective ending", "tool; utensil; means; possess; ingredients; counter for armor, suits, sets of furniture", "assets; resources; capital; funds; data; be conducive to; contribute to", "occasion; side; edge; verge; dangerous; adventurous; indecent; time; when", "reality; truth", "give; bestow; perform; alms", "linen; cloth; spread; distribute", "together; both; neither; all; and; alike; with", "possess; have; exist; happen; occur; approx", "stick; paste; apply", "gain; get; find; earn; acquire; can; may; able to; profit; advantage; benefit", "idea; mind; heart; taste; thought; desire; care; liking", "shake; wave; wag; swing", "crowded; mixture; in bulk; included; (kokuji)", "return; answer; fade; repay", "use; send on a mission; order; messenger; envoy; ambassador; cause", "building; mansion; large building; palace", "map; drawing; plan; extraordinary; audacious", "posture; build; pretend", "pipe; tube; wind instrument; drunken talk; control; jurisdiction", "logic; arrangement; reason; justice; truth", "general; whole; all; full; total", "elect; select; choose; prefer", "beforehand; previous; myself; I", "ward off; defend; protect; resist", "determine; fix; establish; decide", "tongue; reed; clapper", "even; flat; peace", "resign; word; term; expression", "code; ceremony; law; rule", "person in charge; connection; duty; concern oneself", "number; strength; fate; law; figures", "utmost; most; extreme", "first time; beginning", "contact; touch; feel; hit; proclaim; announce; conflict", "mediator; go-between", "accept; undergo; answer (phone); take; get; catch; receive", "take; fetch; take up", "unusual; change; strange", "open; unfold; unseal", "even; flat; peace", "bend; music; melody; composition; pleasure; injustice; fault; curve; crooked; perverse; lean", "line; track", "king; rule; magnate", "employee; member; number; the one in charge", "valve; petal; braid; speech; dialect; discrimination; dispose of; distinguish; conical cap", "gentleman; scholar; samurai; samurai radical (no. 33)", "face; expression", "mask; face; features; surface", "pond; cistern; pool; reservoir", "marsh; lake; bog; swamp; pond", "choose; select; elect; prefer", "town; village; block; street", "snow", "shellfish", "thread", "insect; bug; temper", "grove; forest", "location; place", "rice; USA; metre", "traffic; pass through; avenue; commute; counter for letters, notes, documents, etc.", "neck; counter for songs and poems", "make; production; prepare; build", "strong", "market; city; town", "public; prince; official; governmental", "plains; field; rustic; civilian life", "think", "spot; point; mark; speck; decimal point", "lively; resuscitation; being helped; living", "meadow; original; primitive; field; plain; prairie; tundra; wilderness", "mingle; mixing; association; coming & going", "near; early; akin; tantamount", "consider; think over", "sell", "association; braid; plait; construct; assemble; unite; cooperate; grapple", "know; wisdom", "pull; tug; jerk; admit; install; quote; refer to", "plot; plan; scheme; measure", "straightaway; honesty; frankness; fix; repair", "morning; dynasty; regime; epoch; period; (North) Korea", "pedestal; a stand; counter for machines and vehicles", "wide; broad; spacious", "evening", "teach; faith; doctrine", "cut; cutoff; be sharp", "calculate; divining; number; abacus; probability", "parent; intimacy; relative; familiarity; dealer (cards)", "shape; form; style", "head; counter for large animals", "gate; counter for cannons", "solution; answer", "homecoming; arrive at; lead to; result in", "valley", "song; sing", "ray; light", "department; course; section", "dainty; get thin; taper; slender; narrow; detailed; precise", "round; full (month); perfection; -ship; pills; make round; roll up; curl up; seduce; explain away", "room; apartment; chamber; greenhouse; cellar", "walk; counter for steps", "wind; air; style; manner", "paper", "door; counter for houses; door radical (no. 63)", "park; garden; yard; farm", "fee; materials", "nothingness; none; ain't; nothing; nil; not", "No.; residence", "world; boundary", "year-end; age; occasion; opportunity", "mister; you; ruler; male name suffix", "risk; face; defy; dare; damage; assume (a name)", "revolve; turn around; change", "occasion; side; edge; verge; dangerous; adventurous; indecent; time; when", "accomplished; reach; arrive; attain", "witch; demon; evil spirit", "uncommon; different; queerness; strangeness; wonderful; curious; unusual", "reflect; reflection; projection", "exertion; endeavour; encourage; strive; make effort; diligent", "rouse; wake up; get up", "lie down; sleep; rest; bed; remain unsold", "sort of thing; so; if so; in that case; well", "meal; boiled rice", "end; close; tip; powder; posterity", "simple; one; single; merely", "somebody; person; one's station in life", "question; ask; problem", "angle; corner; square; horn; antlers", "marsh; lake; bog; swamp; pond", "beauty; beautiful", "short; brevity; fault; defect; weak point", "lightly; trifling; unimportant", "feathers; counter for birds, rabbits", "ship; boat", "laugh", "boulder; rock; cliff", "cloud", "chirp; cry; bark; sound; ring; echo; honk", "bow; bow (archery, violin)", "harbor", "storey; stair; counter for storeys of a building", "path; route; road; distance", "bad; vice; rascal; false; evil; wrong", "other; another; the others", "bridge", "beach", "guest; visitor; customer; client", "ascend; climb up", "quick; fast", "center; middle"};

bool flash_cards(string str, int randomNumber, vector<int>& forgotten, bool is_next, bool to_return, int num, bool& go_to_forgotten){
    cout << "█▄▀ ▄▀█ █▄░█ ░░█ █   █▀▀ █░░ ▄▀█ █▀ █░█   █▀▀ ▄▀█ █▀█ █▀▄ █▀\n" << 
            "█░█ █▀█ █░▀█ █▄█ █   █▀░ █▄▄ █▀█ ▄█ █▀█   █▄▄ █▀█ █▀▄ █▄▀ ▄█\n" << std::endl;

    cout << num << ". " << kanji[randomNumber] << ' ';

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
                    is_next = true;
                    break;

                } else if (str == "e"){
                    to_return = true;
                    return to_return;

                } else if (str != "q" && str != "e" && !str.empty()){
                    forgotten.push_back(randomNumber);
                    system("clear");
                    is_next = true;
                    break;
                } else if (str == "q"){
                    system("clear");
                    go_to_forgotten = true;
                    return to_return;
                }
            }   
        } else if (str == "e"){
            to_return = true;
            return to_return;

        } else if (str != "q" && str != "e" && !str.empty()){
            forgotten.push_back(randomNumber);
            system("clear");
            is_next = true;
            break;
        } else if (str == "q"){
            system("clear");
            go_to_forgotten = true;
            return to_return;
        }

        if(is_next){
            break;
        }
    } 

    return false;
}

int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, SIZE - 1);

    string str;
    bool is_in_Nums = false, is_next = false, to_return = false, go_to_forgotten = false;
    int randomNumber;

    vector<int> Nums;
    vector<int> forgotten;

    while(Nums.size() <= SIZE - 1){
        is_in_Nums = false;
        is_next = false;
        to_return = false;
        randomNumber = distr(gen);

        for(int i = 0; i < Nums.size(); i++){
            if(randomNumber == Nums[i]){
                is_in_Nums = true;
            }
        }

        
        if(is_in_Nums != true){
            Nums.push_back(randomNumber);

            if(flash_cards(str, randomNumber, forgotten, is_next, to_return, Nums.size(), go_to_forgotten)){
                return 0;
            } 
            if(go_to_forgotten && forgotten.size() != 0){
                break;
            }
        } 
        
    }
    
    while(true){
        if(forgotten.size() == 0){
            cout << "You did everything, congratulations:D" << "\n";
            while(getline(cin, str)){
                if(str.empty()){
                    system("clear");
                    return 0;
                }
            } 
        } else {
            cout << "Wait... you forgot some? Lets try again then" << "\n\n";
            int y = forgotten.size();
            
            for(int i = 0; i < y; i++){
                is_next = false;
                go_to_forgotten = false;
                randomNumber = forgotten.back();

                if(flash_cards(str, randomNumber, forgotten, is_next, to_return, i + 1, go_to_forgotten)){
                    return 0;
                }
                forgotten.pop_back();
            }
        }
    }
      
    return 0;
}