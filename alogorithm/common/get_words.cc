// get words from a single line string split by whitespaces.
void GetWords(const string& line, vector<string>& words) {
  if (line.empty()) return;
  size_t st_pos, ed_pos;
  ed_pos = 0;
  while (ed_pos < line.size()) {
    st_pos = line.find_first_not_of(' ', ed_pos);
    if (st_pos == string::npos) break;
    ed_pos = line.find_first_of(' ', st_pos);
    if (ed_pos == string::npos) ed_pos = line.size();
    words.push_back(line.substr(st_pos, ed_pos - st_pos));
  }
}