# playbook

```yml
---
- name: apply configuration to all nodes
  hosts: all
  remote_user: tan

  roles: 
    - common
    - nginx
    - myapp

---
# production
[webservers]
192.168.56.101

---
# stage
[webservers]
example.com

---
# group_vars/all
httpd_port: 8080
repository: https://github.com/thjxs/test.git
app_path: /home/tan/web

---
# roles/nginx/handlers/main.yml
- name: restart nginx
  remote_user: root
  service: name=nginx state=restarted enabled=yes

---
# roles/nginx/tasks/main.yml
- name: install nginx
  yum: name=nginx state=present

- name: copy nginx configuration
  become: yes
  become_method: sudo
  template: src=default.conf dest=/path/to/default.conf
  notify: restart nginx

---
# roles/nginx/templates/default.conf

---
# roles/myapp/tasks/main.yml
- name: copy the code
  git: repo={{ repository }} dest={{ app_path }}

```
