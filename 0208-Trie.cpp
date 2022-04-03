/**
 * author:Lazxs
 * date:2022-04-03 
 * Annotations here for reviewing my stupidity accidentally.
 */

class Trie {
	struct TrieNode { //结构体代表一个节点
		TrieNode *child[26] = { NULL }; //一个节点有26个子，都被初始化为NULL
		bool isEnd = false; //默认节点不是最后一个字符
	};
public:
	TrieNode *trie; //初始化母节点
	Trie() {
		trie = new TrieNode();
	}

	void insert(std::string word) {
		int len = word.size();  //字符个数
		TrieNode* currNode = trie; //当前节点为母节点
		for (int i = 0; i != len; i++) { //对所有字符逐个循环
			int ch = word[i] - 'a'; //求字符下标
			if (ch > -1 && ch < 26) { //下标应该在【0，25】
				if(!currNode->child[ch]) currNode->child[ch] = new TrieNode(); //如果这个子节点是空，那就初始化它
				currNode = currNode->child[ch]; //把子节点设置为当前节点
				//if(i==(len-1)) currNode->isEnd = true;
			}
		}
		currNode->isEnd = true;//如果是最后一个字符，将当前节点的isEnd设置为true
	}

	bool search(std::string word) {
		int len = word.size(); //字符长度
		TrieNode* currNode = trie; //当前节点为母节点
		for (int i = 0; i != len; i++) { //读取每一个字符
			int ch = word[i] - 'a'; //求字符下标
			if (currNode->child[ch]) { //如果节点不空，代表字符（串）前缀存在
				currNode = currNode->child[ch]; //把当前节点移到下一个位置
				if (i == (len - 1)&&currNode->isEnd) return true; // 如果位于字符串末端且有是End节点，成功
			}
			else return false;// 任意一个位置不匹配，失败
		}
		return false; //不会到达这里，修复警告
	}

	bool startsWith(std::string prefix) {
		int len = prefix.size();//字符长度
		TrieNode* currNode = trie;//当前节点为母节点
		for (int i = 0; i != len; i++) {//读取每一个字符
			int ch = prefix[i] - 'a'; //求字符下标
			if (!currNode->child[ch]) return false; //如果节点为空，代表字符（串）前缀不存在，失败
			currNode = currNode->child[ch]; //当前节点更新
		} 
		return true; //逐字符循环结束，成功
	}
};
