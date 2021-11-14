#include <bits/stdc++.h>
using namespace std;
class Document;
class directory;
int n;
typedef pair<string, bool> PSB; //next directory,reached
typedef long long ll;
set<Document> book;

PSB getNext(string &path) //在修改path的同时，若p.second==true则返回最后的文件名（文件夹名），若为false则返回最左侧的文件夹名
{
  if (path == "/" || path == "")
    return make_pair("", true);
  //root

  int pos = path.find_first_of('/', 1);
  string ret;
  if (pos == string::npos) // "/A"
  {
    ret = path.substr(1);
    path = "";
    return make_pair(ret, true);
  }
  else // "/A/B"
  {
    ret = path.substr(1, pos - 1);
    path = path.substr(pos);
    return make_pair(ret, false);
  }
}

class Document //Documentument
{
public:
  ll size;
  string addd = ""; //adddress (for maintainance of book)
  string name;
  Document(string newName, ll ns = 0) : name(newName), size(ns) { this->addd = ""; }
  Document(string newName, ll ns, string addd) : Document(newName, ns) { this->addd = addd; }
};
bool operator<(const Document &a, const Document &b)
{
  return a.name < b.name;
}
struct Pdirectory
{
  directory *ptr;
  string name;

  Pdirectory(string nn = "", directory *np = nullptr) : name(nn), ptr(np) {}
};
bool operator<(const Pdirectory &a, const Pdirectory &b)
{
  return a.name < b.name;
}
class directory //directoryectory
{
public:
  ll ld = 0;                   //目录配额(孩子）
  ll lr = 0;                   //后代配额
  ll nwD = 0;                  //目录下（不含子目录）的文件大小
  ll nwR = 0;                  //目录下所有文件（包含子目录）的大小
  set<Document> DocumentS;     // Document set
  set<Pdirectory> PdirectoryS; // Pdirectory set

  bool createDocument(const string &fullPath, string path, const ll &size)
  {
    if (lr != 0 && nwR + size > lr)
      return false;
    PSB p = getNext(path); //curr name, reached?

    if (p.second) //如果已经在指定目录下，就在该目录下分配
    {
      if ((ld != 0 && nwD + size > ld) || PdirectoryS.find(Pdirectory(p.first)) != PdirectoryS.end()) //且超出限额 或 存在同名文件夹
        return false;
      nwD += size;
      book.emplace(fullPath, size);
      DocumentS.emplace(p.first, size, fullPath);
    }
    else //如果尚未达到
    {
      if (DocumentS.find(p.first) != DocumentS.end()) //要创建文件夹时出现了同名文件
        return false;

      auto it = PdirectoryS.find(Pdirectory(p.first));

      bool newlyCreate = false;
      if (it == PdirectoryS.end())
      {
        newlyCreate = true;
        it = PdirectoryS.emplace(p.first, new directory()).first;
      }

      if (it->ptr->createDocument(fullPath, path, size) == false)
      {
        if (newlyCreate)
          PdirectoryS.erase(it);
        return false;
      }
    }
    nwR += size;
    return true;
  }
  bool stLimi(string path, ll ld, ll lr) //设置限额
  {
    PSB p = getNext(path);
    if (p.first == "") //setQ的地址的最后一个是文件夹，所以将终止条件由p.second==true 改为 p.first==""
    {
      if ((lr != 0 && nwR > lr) || (ld != 0 && nwD > ld))
        return false;
      this->ld = ld;
      this->lr = lr;
    }
    else
    {
      auto it = PdirectoryS.find(p.first);
      if (it == PdirectoryS.end() || it->ptr->stLimi(path, ld, lr) == false)
        return false;
    }
    return true;
  }
  bool reDo(const string &fullPath, string path, const ll &sizeCh)
  {
    PSB p = getNext(path);
    if (lr != 0 && nwR + sizeCh > lr)
      return false;
    if (p.second) //在当前目录下更改文件
    {
      if (ld != 0 && nwD + sizeCh > ld)
        return false;

      nwD += sizeCh;
      auto it = (book.find(fullPath));
      Document tmp = *it;
      book.erase(*it);
      book.emplace(fullPath, tmp.size + sizeCh);

      it = DocumentS.find(p.first);
      tmp = *it;
      DocumentS.erase(it);
      DocumentS.emplace(p.first, tmp.size + sizeCh, fullPath);
    }
    else if (PdirectoryS.find(Pdirectory(p.first))->ptr->reDo(fullPath, path, sizeCh) == false) //在子目录的添加中失败了
      return false;

    nwR += sizeCh;
    return true;
  }
  ll delFile(string path) //delete
  {
    PSB p = getNext(path);
    if (p.second) //要删除的文件（夹）就在当前文件夹下
    {
      auto di = DocumentS.find(p.first);
      if (di != DocumentS.end()) //寻找同名文档
      {
        ll ret = di->size;
        book.erase(di->addd);
        DocumentS.erase(di);
        nwD -= ret;
        nwR -= ret;
        return ret;
      }
      else //寻找同名文件夹
      {
        auto pi = PdirectoryS.find(p.first);
        if (pi == PdirectoryS.end())
          return 0; //not found
        ll ret = pi->ptr->nwR;
        nwR -= ret;
        delete pi->ptr;
        PdirectoryS.erase(pi);
        return ret;
      }
    }
    else
    {
      auto pi = PdirectoryS.find(p.first);
      if (pi == PdirectoryS.end())
        return 0;
      ll toDel = pi->ptr->delFile(path);
      nwR -= toDel;
      return toDel;
    }
  }
  ~directory()
  {
    for (Document i : DocumentS)
      book.erase(i.addd);
    for (Pdirectory i : PdirectoryS)
      if (i.ptr != nullptr)
        delete i.ptr;
  }

} root;

void otRes(bool f) //output result
{
  if (f)
    cout << "Y" << '\n';
  else
    cout << "N" << '\n';
}

int main()
{
  ios::sync_with_stdio(false);

  cin >> n;
  while (n--)
  {
    char cmd;
    string addd;
    cin >> cmd >> addd;
    if (cmd == 'C')
    {
      ll size;
      cin >> size;
      auto it = book.find(addd);
      if (it != book.end())
        otRes(root.reDo(addd, addd, size - it->size));
      else
        otRes(root.createDocument(addd, addd, size));
    }
    else if (cmd == 'R')
    {
      root.delFile(addd);
      cout << "Y" << '\n';
    }
    else //Q
    {
      ll ld, lr;
      cin >> ld >> lr;
      otRes(root.stLimi(addd, ld, lr));
    }
  }
  return 0;
}