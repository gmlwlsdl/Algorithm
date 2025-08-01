import re
import os
import subprocess
from urllib.parse import quote

def get_latest_commit_info():
    """가장 최근의 커밋 메시지와 추가된 파일 목록을 가져옵니다."""

    # git log 명령을 실행하여 마지막 커밋의 정보(커밋 메시지, 파일 상태)를 가져옵니다.
    result = subprocess.run(
        ['git', 'log', '-1', '--name-status', '--pretty=%s'],
        capture_output=True, text=True, encoding='utf-8'
    )

    lines = result.stdout.strip().split('\n')
    commit_message = lines[0]  # 첫 번째 줄은 커밋 메시지입니다.

    # 'A\t'로 시작하는 줄(추가된 파일)에서 파일 경로만 추출합니다.
    added_files = [line.split('\t')[1] for line in lines[1:] if line.startswith('A\t')]

    return commit_message, added_files

def parse_problem_info(commit_message, added_files):
    """커밋 메시지와 파일 경로에서 문제 정보를 파싱합니다."""

    # BaekjoonHub 커밋이 아니면 None을 반환합니다.
    if "-BaekjoonHub" not in commit_message:
        return None

    for file_path in added_files:

        # git log에서 가져온 8진수 이스케이프 시퀀스를 디코딩합니다.
        decoded_path = file_path.encode('latin1').decode('unicode_escape')

        # 정규식을 사용하여 파일 경로에서 티어, 문제 번호, 문제 제목을 추출합니다.
        match = re.search(r'백준/(?P<tier>Bronze|Silver|Gold|Platinum)/'
                          r'(?P<problem_num>\d+)\. (?P<problem_title>.+?)/', decoded_path)
        
        if match:
            info = match.groupdict()

            # 디렉토리 이름 (예: "1000. A+B") 을 생성합니다.
            info['problem_dir'] = f"{info['problem_num']}. {info['problem_title']}"
            return info
        
    return None

def update_readme(problem_info):
    """새로운 문제 정보를 README.md에 추가하고 정렬된 상태를 유지합니다."""

    readme_path = 'README.md'
    tier = problem_info['tier']
    problem_dir = problem_info['problem_dir']
    
    # GitHub 레포지토리 URL과 문제 디렉토리 경로를 조합하여 전체 URL을 생성합니다.
    repo_url = "https://github.com/gmlwlsdl/Algorithm/tree/main"

    # URL에 한글이나 특수문자가 포함될 수 있으므로 안전하게 인코딩합니다.
    problem_url = f"{repo_url}/백준/{tier}/{quote(problem_dir)}"

    # README에 추가될 새로운 줄(마크다운 링크)을 생성합니다.
    new_line = f"- [{problem_dir.replace(' ', ' ')}]({problem_url})\n"

    with open(readme_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    # 해당 티어의 헤더(예: "### Silver")를 찾습니다.
    tier_header = f"### {tier}\n"
    try:
        header_index = lines.index(tier_header)
    except ValueError:
        # 티어 헤더를 찾지 못하면 오류 메시지를 출력하고 종료합니다.
        print(f"Tier section '{tier}' not found in README.md.")
        return

    # 해당 티어의 문제 목록이 시작되고 끝나는 지점을 찾습니다.
    list_start_index = header_index + 1
    list_end_index = list_start_index
    while list_end_index < len(lines) and lines[list_end_index].strip().startswith('- ['):
        list_end_index += 1

    problem_list = lines[list_start_index:list_end_index]
    
    # 중복 추가를 방지하기 위해 이미 문제가 목록에 있는지 확인합니다.
    if any(problem_dir in line for line in problem_list):
        print(f"Problem '{problem_dir}' already exists in README.md.")
        return

    # 새로운 문제를 목록에 추가하고 문제 번호 순으로 정렬합니다.
    problem_list.append(new_line)
    problem_list.sort(key=lambda x: int(re.search(r'(\d+)', x).group(1)))

    # 기존의 목록 부분을 새로 정렬된 목록으로 교체합니다.
    new_readme_content = lines[:list_start_index] + problem_list + lines[list_end_index:]

    with open(readme_path, 'w', encoding='utf-8') as f:
        f.writelines(new_readme_content)
    print(f"Successfully added '{problem_dir}' to {tier} section and sorted the list.")

if __name__ == "__main__":
    # 스크립트가 직접 실행될 때 호출되는 부분입니다.
    commit_msg, files = get_latest_commit_info()
    info = parse_problem_info(commit_msg, files)
    
    if info:
        # 문제 정보가 성공적으로 파싱되면 README를 업데이트합니다.
        update_readme(info)
    else:
        # BaekjoonHub 커밋이 아니면 메시지를 출력합니다.
        print("No new Baekjoon problem found in the latest commit.")


